#include <bits/stdc++.h>
using namespace std;

int gcd3(int a, int b, int c){
  return gcd(a, gcd(b,c));
}

int main(){
  int K;
  cin>>K;
  int gcd_sum=0;
  for (int a=1; a<=K; a++){
    for (int b=1; b<=K; b++){
      for (int c=1; c<=K; c++){
        gcd_sum+=gcd3(a,b,c);
      }
    }
  }
  cout<<gcd_sum<<endl;
}