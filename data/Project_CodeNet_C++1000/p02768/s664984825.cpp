#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll repeatpow(ll n, ll p, ll m){
  if(p==0) return 1;
  if(p%2==0){
    ll t=repeatpow(n, p/2, m);
    return t*t%m;
  }
  return n*repeatpow(n, p-1, m)%m;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll mod=1000000007;
  ll sum=repeatpow(2, n, mod)-1;
  ll ax=1, ay=1, bx=1, by=1;
  for(ll i=1; i<=a; i++){
    ax=ax*(n-i+1)%mod;
    ay=ay*i%mod;
  }
  for(ll i=1; i<=b; i++){
    bx=bx*(n-i+1)%mod;
    by=by*i%mod;
  }
  ll ayinv=repeatpow(ay, mod-2, mod)%mod;
  ll byinv=repeatpow(by, mod-2, mod)%mod;
  ll asum=ax*ayinv%mod, bsum=bx*byinv%mod;
  ll ans=(sum-asum-bsum)%mod;
  if(ans<0) ans+=mod;
  cout <<ans;
  return 0;
}