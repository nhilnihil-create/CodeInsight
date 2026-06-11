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
  ll N,K,i;scanf("%lld%lld",&N,&K);
  //comb(K-1,i)*comb(N-K+1,i+1)
  ll E[2001];E[0] = E[1] = 1;
  for(i=2;i<=2000;i++) E[i] = E[i-1]*i%mod;
  for(i=0;i<K;i++){
    if(N-K < i) printf("0\n");
    else printf("%lld\n",E[K-1]*modinv(E[i])%mod*modinv(E[K-1-i])%mod*E[N-K+1]%mod*modinv(E[i+1])%mod*modinv(E[N-K-i])%mod);
  }
}