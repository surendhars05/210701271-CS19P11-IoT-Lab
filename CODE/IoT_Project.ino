#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensorPin=A0;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue=analogRead(sensorPin);
  int turbidity=map(sensorValue,0,615,100,0);
   delay(100);
   lcd.setCursor(0,0);
   lcd.print("Turbidity:");
   lcd.print("  ");
   lcd.print(turbidity);
   delay(100);
   if(turbidity<20){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    lcd.setCursor(0,1);
    lcd.print(" its CLEAR ");
   }
    if(turbidity>20 && turbidity<50){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    lcd.setCursor(0,1);
    lcd.print(" its CLOUDY ");
   }
    if(turbidity>50){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    lcd.setCursor(0,1);
    lcd.print(" its DIRTY ");
   }

}
