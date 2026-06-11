#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long a,b,c;
  a=1;
  b=1;
  c=1;
  for(long long i=0;i<n;i++){
    a=(a*10)%1000000007;
  }
  for(long long i=0;i<n;i++){
    b=(b*9)%1000000007;
  }
  for(long long i=0;i<n;i++){
    c=(c*8)%1000000007;
  }
  long long d;
  d=0;
  d=(a+c-(2*b)%1000000007)%1000000007;
  if(d<0){
    d=1000000007+d;
  }
  cout<<d;
}