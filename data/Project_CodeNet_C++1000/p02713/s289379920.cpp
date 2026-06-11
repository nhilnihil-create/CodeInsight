#include<bits/stdc++.h>
using namespace std;
int gcd(int A,int B){
  if(B==0){
    return A;
  }
  return gcd(B,A%B);
}
int main(){
  int K;
  cin >> K;
  long long sum=0;
  for(int a=1;a<K+1;a++){
    for(int b=1;b<K+1;b++){
      for(int c=1;c<K+1;c++){
        sum+=gcd(a,gcd(b,c));
      }
    }
  }
  cout << sum << endl;
}