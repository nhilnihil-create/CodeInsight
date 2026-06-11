#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
  string Taro, Hanako;
  int Turn, markT=0, markH=0;

  cin >> Turn;

  for(int i=0; i<Turn; i++){
    cin >> Taro >> Hanako;

    if(Taro > Hanako){
      markT += 3;
    }else if(Taro < Hanako){
      markH += 3;
    }else{
      markT++;
      markH++;
    }
  }
  
  cout << markT << " " << markH << endl;
  
  return(0);

}