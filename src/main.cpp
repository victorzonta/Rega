#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd( 2, 3, 4, 5, 6 ,7);

int Rele =10;
int Sensor = A0;
int umidade;

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(Rele, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
umidade = analogRead(Sensor);
Serial.print("umidade: ");
Serial.print(umidade);

if (umidade >600) {
  lcd.clear();
  lcd.print("estou com sede");
  digitalWrite(Rele, HIGH);
}
else {
  lcd.clear();
  lcd.print("valeu!! ");
  digitalWrite(Rele, LOW);
}
delay(1000);// delay de 1segundo
}