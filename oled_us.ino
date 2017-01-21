#include <U8glib.h>


//created by SAYANTIKA BANIK


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);
# define trigpin 3
# define echopin 2

void setup() 
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  u8g.setFont(u8g_font_courB12);
  u8g.setColorIndex(2);
  Serial.println("LCD test with PWM contrast adjustment");
 
}

void loop() 
{
  
float distance,val;
float duration;
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin,HIGH);
   delayMicroseconds(1);
 
  duration=pulseIn(echopin,HIGH, 50000);
  distance=(duration*.034)/2; //distance in cms
  
Serial.print("Duration->");
Serial.println(duration);
Serial.print("Distance->");
  Serial.println(distance);
  u8g.firstPage();
              do {  
                    u8g.setPrintPos(15, 30);
                   
                   u8g.print(distance);
                   if (duration>250&&duration<480){
                   u8g.drawStr(60,60,"BREAK!");
                    delay(100);
                  }
                    else
                    { 
                   u8g.drawStr(60,60,"SAFE!");
                    delay(100);
                    }
           
                 
                 } while( u8g.nextPage() );
             
  delay(200);
  //to disp. distance on to the serial monitor
 
  //to disp. duration on to the serial monitor

}
 





