#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
  if(x%y==0){
    return y;
  }
  return gcd(y,x%y);
}
long long lcm(long long p,long long q){
  return (p*q)/gcd(p,q);
}
int main(){
  long long a,b;
  cin>>a>>b;
  cout<<lcm(a,b)<<endl;
  return 0;
}
