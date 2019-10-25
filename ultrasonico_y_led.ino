int trigger = 10;           // declaramos la palabra trigger como un tipo entero y al mismo tiempo reemplaza al pin 9
int echo = 9;           // declaramos la palabra echo como un tipo entero y al mismo tiempo reemplaza al pin 8
float tiempo_de_espera, distancia; // creamos una variable de fotante; es decir, nos puede dar resultados en decimales.
//const int ledPin1 =  2;
//int i; 
//const int ledPin2 =  5;  

#define led 2
void setup() {
  Serial.begin (9600);   // establemos la comucicacion serial
  pinMode (trigger, OUTPUT); // declarmos el pin 9 como salida
  pinMode (echo, INPUT);   // declaramos el 8 como entrada
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite (trigger, LOW); // ponemos en bajo el pin 8 durante 2 microsegundos
  delayMicroseconds(2);
  digitalWrite (trigger, HIGH);// ahora ponemos en alto pin 8 durante 10 microsegundos;
  delayMicroseconds (10);     // pues este el momento en que emite el sonido durante 10 segungos
  digitalWrite (trigger, LOW); // ahora ponemos en bajo pin 8

  tiempo_de_espera = pulseIn (echo, HIGH); // pulseIn, recoge la señal del sonido que emite el trigger
  /*La función pulseIn espera la aparición de un pulso en una entrada y mide su duración, dando como resultado la duración medida
    El primer parámetro (ECHO) es el pin sobre el que se realizará la medición.
    Y el segundo parámetro (HIGH) indica si el pulso a esperar será un 1 (HIGH) o un 0 (LOW).
  */
  distancia = (tiempo_de_espera / 2) / 29.15; // formula para hallar la distancia

  Serial.print (distancia);    // imprimimos la distancia en cm
  Serial.println ("cm");
  delay (1000);
  if (distancia >= 10 && distancia <= 500) { 
    digitalWrite (led, HIGH);

  }    else
      digitalWrite (led, LOW);
      delay (500);
      
    //for  (i = 1; i < 255; i++) {
   // analogWrite(ledPin1, i);
  //  delay(5);
  }
  //for  (i = 255; i > 0; i--) {
   // analogWrite(ledPin1, i);
   // delay(5);
  
   // analogWrite (3, 0);
    //analogWrite (4, 0);
    //analogWrite (5, 0);
   // analogWrite (6, 0);
    //analogWrite (7, 0);
    //analogWrite (8, 0);
  
