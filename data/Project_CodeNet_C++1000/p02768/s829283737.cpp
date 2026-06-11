#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll modpow(ll x,ll y){
  ll ans = 1;
  while(y){
    if(y&1) ans = ans*x%mod;
    x = x*x%mod;
    y >>= 1;
  }
  return ans;
}
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
ll P(ll n){
  ll ans = 1;
  while(n){
    ans = ans*n%mod;n--;
  }
  return ans;
}
ll nCr(ll n,ll r){
  ll ans = 1;
  for(ll i=n;i>n-r;i--) ans = ans*i%mod;
  ans = ans*modinv(P(r))%mod;
  return ans;
}
int main(){
  ll n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
  ll ans = modpow(2,n)-1-nCr(n,a)-nCr(n,b);
  ans %= mod;
  if(ans < 0) ans += mod;
  printf("%lld\n",ans);
}