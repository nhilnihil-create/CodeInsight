#include<iostream>
using namespace std;

int main(void){
  long long X;
  cin >> X;
  
  long long N=100;
  int count=0;
  
  while(1){
    N += N/100;
    count++;
    
    if(N>=X){
      break;
    }
  }
  
  cout << count << endl;
  
  return 0;
}