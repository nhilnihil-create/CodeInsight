#include <bits/stdc++.h>
using namespace std;
long long gcd(long long n,long long m){
  if(n%m==0){
    return m;
  }
  return gcd(m,n%m);
}
long long lcm(long long a,long long b){
  return (a*b)/gcd(a,b);
}
int main(){
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long x=(b/c)-(a/c);
  long long y=(b/d)-(a/d);
  long long g=lcm(c,d);
  long long z=(b/g)-(a/g);
  if(a%c==0)x=(b/c)-(a/c)+1;
  if(a%d==0)y=(b/d)-(a/d)+1;
  if(a%g==0)z=(b/g)-(a/g)+1;
  cout<<(b-a+1)-(x+y-z)<<endl;
  return 0;
}