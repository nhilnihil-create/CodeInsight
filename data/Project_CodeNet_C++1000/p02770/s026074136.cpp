#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll k, q;
  scanf("%lld %lld",&k,&q);
  ll ans[q], d[k], dm[k];
  rep(i,k) scanf("%lld",&d[i]);
  ll n, x, m, s, f;
  rep(i,q) {
    scanf("%lld %lld %lld",&n,&x,&m);
    s = 0, f = x;
    rep(j,k) {
      dm[j] = d[j] % m;
      if(dm[j] == 0) dm[j] = m;
      s += dm[j];
    }
    f += s * ((n-1) / k);
    int p = (n-1) % k;
    rep(j,p) f += dm[j];
    ans[i] = n - 1 - (f / m - x / m);
  }
  for(auto t : ans) printf("%lld\n",t);
  return 0;
}