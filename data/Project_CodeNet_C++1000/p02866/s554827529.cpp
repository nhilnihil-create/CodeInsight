#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

static const ll MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) {
    int dd;
    cin >> dd;
    // 0番目は必ず0
    // 0番目以外は0でない
    if ((i == 0 && dd != 0) || (i != 0 && dd == 0)) {
      cout << 0 << endl;
      return 0;
    }
    d.at(i) = dd;
  }
  map<int, int> mp;
  for (int dd : d) {
    mp[dd]++;
  }
  ll res = 1;
  rep(i, mp.size()) {
    if (i == 0) {
      continue;
    }
    ll x = (ll) mp[i];
    ll parent = (ll) mp[i - 1];
    rep(j, x) {
      res *= parent;
      res %= MOD;
    }
  }
  cout << res << endl;
  return 0;
}
