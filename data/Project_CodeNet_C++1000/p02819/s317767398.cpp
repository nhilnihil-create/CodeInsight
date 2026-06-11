#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
  if(n<2) return false;
  else if(n==2) return true;
  else if(n%2==0) return false;

  double sqrtN=sqrt(n);
  for(int i=3;i<=sqrtN;i+=2) if(n%i==0) return false;
  return true;
}

int main() {
  int x; cin>>x;
  while(1){
    if(isPrime(x)){
      cout<<x;
      return 0;
    }
    x++;
  }
}