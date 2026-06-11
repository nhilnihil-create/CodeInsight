#include<bits/stdc++.h>
using namespace std;

bool isprime(int X){
  if(X==1){
    return false;
  }
  for(int i=2;i*i<=X;i++){
    if(X%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int X;
  cin >> X;
  while(true){
    if(isprime(X)){
      cout << X << endl;
      return 0;
    }
    X++;
  }
}