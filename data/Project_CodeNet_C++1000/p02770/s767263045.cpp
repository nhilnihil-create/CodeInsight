#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll k, q;
  cin >> k >> q;
  vector<ll> ans(q);
  ll d[k];
  rep(i,k) cin >> d[i];
  rep(i,q) {
    ll n, x, m;
    cin >> n >> x >> m;
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
  for(auto t : ans) cout << t << endl;
  return 0;
}