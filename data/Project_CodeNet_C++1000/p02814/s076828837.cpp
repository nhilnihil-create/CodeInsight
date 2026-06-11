#include<bits/stdc++.h>
using namespace std;
long long mul2(long long z)
  {
    long long s=0;
    while(z%2==0){s++; z/=2;}
    return s;
  }
int main(){
  long long n,m; cin >>n >>m; long long lmul=1; 
  vector<long long>v(n);
  
  for(int i=0; i<n; i++)
  {
    cin >>v[i]; v[i]/=2;
    long long cnt=mul2(v[0]);
    if(mul2(v[i])!=cnt){cout <<0; return 0;}
    else lmul=lmul*v[i]/__gcd(lmul,v[i]);
  }
cout <<(m/lmul+1)/2;
return 0;}