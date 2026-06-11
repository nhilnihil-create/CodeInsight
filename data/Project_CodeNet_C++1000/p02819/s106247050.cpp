#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
  bool ans = true;
  for(int i=2; i<x; i++){
    if(x%i == 0) {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  int X;
  cin>>X;
  bool a = false;
  while(!a){
    if(isPrime(X)){
      cout<<X<<endl;
      a=true;
    }
    X++;
  }
}