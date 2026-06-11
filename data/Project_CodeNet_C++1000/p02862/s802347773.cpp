#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll modinv(ll a){
  ll b = mod,u = 1,v = 0,t;
  while(b){
    t = a/b;
    a -= t*b;swap(a,b);
    u -= t*v;swap(u,v);
  }
  u %= mod;
  if(u < 0) u += mod;
  return u;
}
int main(){
  ll X,Y,l,i;scanf("%lld%lld",&X,&Y);
  if((X+Y)%3 != 0){
    printf("0\n");return 0;
  }
  l = (X+Y)/3;
  X -= l;Y -= l;
  if(X < 0 || Y < 0){
    printf("0\n");return 0;
  }
  ll B[X+Y+1];B[0] = B[1] = 1;
  for(i=2;i<=X+Y;i++) B[i] = B[i-1]*i%mod;
  printf("%lld\n",B[X+Y]*modinv(B[X])%mod*modinv(B[Y])%mod);
}