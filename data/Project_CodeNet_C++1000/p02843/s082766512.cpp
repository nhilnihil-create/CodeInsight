#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X;
  int Y;
  cin>>X;
  if((X%100)%5==0){
    Y=(X%100)/5;
  }
  else{
    Y=(X%100)/5+1;
  }
  if(Y<=X/100){
    cout<<1<<endl;
  }
  else{
    cout<<0<<endl;
  }
}