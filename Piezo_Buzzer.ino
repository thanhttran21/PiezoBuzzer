
/*  Thanh T. Tran
 *  Summer 2019
 *  Piezo Buzzer
 *  Frankie Valli - Can't Take My Eyes Off of You
 */
 
/*
SparkFun Tinker Kit
Circuit 5: Buzzer

Play notes using a buzzer connected to pin 10

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/activity-guide-for-sparkfun-tinker-kit/
Download drawings and code at: https://github.com/sparkfun/SparkFun_Tinker_Kit_Code/
*/

int speakerPin = 10;               //the pin that buzzer is connected to

void setup()
{
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
}

void loop()
{

  play('u', 4);       
  play('i', 2);  
  play(' ', 1);   
    
  play('u', 4);       
  play('i', 2);  
  play(' ', 1);
       
  play('u', 4);       
  play('i', 2);      
  play('0', 4);       
  play('o', 2); 
  play(' ', 1);
  play('i', 2);

  play('u', 4);       
  play('i', 2);  
  play(' ', 1);   
    
  play('u', 4);     
  play('i', 2);
  play(' ', 1);   
  play('0', 16);  
  play(' ', 3);

  play('d', 2);  // i
  play(' ', 1);   
  play('d', 2);  // love
  play(' ', 1);
  play('d', 2);  // u 
  play(' ', 1);
  play('d', 4);  // baaaa
  play(' ', 1);
  play('9', 3);  // by

  play('9', 2);
  play('p', 2);
  play('s', 2);
  play('d', 3);
  play('d', 1);
  play(' ', 1);
  play('s', 4);

  play('p', 2);
  play('0', 2);
  play('p', 2);
  play('s', 4);
  play(' ', 1);
  play('u', 3);
  play(' ', 1);
  play('u', 2);
  play('9', 2);
  play('0', 2);
  play('s', 3);
  play('s', 1);
  play(' ', 1);
  play('p', 4);

  play('0', 2);
  play('9', 2);
  play('0', 2);
  play('p', 4);
  play(' ', 1);
  play('y', 6);
  play(' ', 1);
  play('p', 3);
  play('p', 1);
  play(' ', 1);
  play('0', 4);
  play('p', 2);
  play('0', 2);
  play('9', 2);
  play('9', 12);
  play(' ', 2);
  play('u', 4);
  

  while(true){}       //get stuck in this loop forever so that the song only plays once
}


void play( char note, int beats)
{
  int numNotes = 24;  // number of notes in our note and frequency array (there are 15 values, but arrays start at 0)

  //Note: these notes are C major (there are no sharps or flats)

  //this array is used to look up the notes
  char notes[] = { 'q', '2', 'w', '3', 'e', 'r', '5', 't', '6', 'y', '7', 'u', 'i', '9', 'o', '0', 'p', 'z', 's', 'x', 'd', 'c', 'f', 'v', 'b', ' '};
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 0};

  int currentFrequency = 0;    //the frequency that we find when we look up a frequency in the arrays
  int beatLength = 150;   //the length of one beat (changing this will speed up or slow down the tempo of the song)

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 14
  {
    if (notes[i] == note)             // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];   // Yes! Set the current frequency to match that note
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(speakerPin, currentFrequency, beats * beatLength);   
  delay(beats* beatLength);   //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}

/* CHART OF FREQUENCIES FOR NOTES IN C MAJOR
Note      Frequency (Hz)
c        262
c#/db    277
d        294
d#/eb    311
e        330
f        349
f#/gb    370
g        392
g#/ab    415
a        440
a#/bb    466
b        494
C        523
C#/DB    554
D        587
D#/EB    622
E        659
F        698
F#/GB    740
G        784
G#/AB    831
A        880
A#/BB    932
B        988
*/
