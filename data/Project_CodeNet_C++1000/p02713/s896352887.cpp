#include<iostream>
using namespace std;

int gcd(int a, int b){
  if (a%b == 0){
    return b;
  }
  else {
    return gcd(b, a%b);
  }
}


int GCD(int a, int b, int c){
  return gcd(a, gcd(b, c));
}

int main(){
  int K;
  cin >> K;
  
  int ans=0;
  
  for (int a=1; a<=K; a++){
    for (int b=1; b<=K; b++){
      for (int c=1; c<=K; c++){
        ans += GCD (a, b, c);
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
