#include<iostream>
using namespace std;

int main(void){

  int first,last,input,i,times;
  times = 0;

  cin >> first >> last >> input;

  for(i=first; i<last+1; i++){
    if(input < i) break;
    if(input % i == 0)
      times++;
  }

  cout << times << endl;

  return 0;

}