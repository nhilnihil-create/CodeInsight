#include <stdio.h>
#include <iostream>
using namespace std;

struct music_t{
  string title;
  int time;
};

int main(void)
{
  int n = 0;
  int sleepflg = 0;
  string endtitle;
  int sleeptime = 0;

  scanf("%d",&n);
  
  music_t music[n];

  for(int i = 0; i < n; i++){
    cin >> music[i].title >> music[i].time;
//    cout << music[i].title << " " << music[i].time << "\n";
  }
  cin >> endtitle;
//  cout << endtitle << "\n";

  for(int i = 0; i < n; i++){
    if(sleepflg == 0){
     if(music[i].title == endtitle){
       sleepflg = 1;
     }
    }else{
      sleeptime = sleeptime + music[i].time;
    }
  }
  
  printf("%d",sleeptime);
}