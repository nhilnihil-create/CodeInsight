#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll k, q;
  cin >> k >> q;
  vector<ll> ans(q);
  ll d[k];
  rep(i,k) scanf("%lld",&d[i]);
  rep(i,q) {
    ll n, x, m;
    scanf("%lld %lld %lld",&n,&x,&m);
    ll dm[k];
    ll s = 0;
    rep(j,k) {
      dm[j] = d[j] % m;
      if(dm[j] == 0) dm[j] = m;
      s += dm[j];
    }
    ll f = x;
    f += s * ((n-1) / k);
    rep(j,(n-1) % k) f += dm[j];
    ans[i] = n - 1 - (f / m - x / m);
  }
  for(auto t : ans) printf("%lld\n",t);
  return 0;
}