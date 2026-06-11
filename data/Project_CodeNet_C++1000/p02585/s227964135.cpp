#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n), c(n);
  rep(i, n) cin >> p[i], p[i]--;
  rep(i, n) cin >> c[i];
  ll ans = -1001001001;
  rep (i, n) {
    int now = i;
    vector<ll> vs;
    ll res = 0;
    do {
      now = p[now];
      res += c[now];
      vs.push_back(res);
    } while (now != i);
    int sz = vs.size();
    rep (j, min(sz, k)) ans = max(ans, vs[j] + ((k - j - 1) / sz) * max(0ll, res));
  }
  cout << ans << endl;
  return 0;
}