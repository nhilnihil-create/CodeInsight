#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n, -1));
  rep(i, n) {
    int a;
    cin >> a;
    rep(j, a) {
      int x, y;
      cin >> x >> y;
      x--;
      d.at(i).at(x) = y;
    }
  }

  ll res = 0;
  rep(i, 1 << n) {
    bool ok = true;
    rep(j, n) {
      if (i >> j & 1) {
        rep(k, n) {
          int x = d.at(j).at(k);
          if (x == -1) {
            continue;
          }
          if (x == 1 && !(i >> k & 1)) {
            ok = false;
          }
          if (x == 0 && (i >> k & 1)) {
            ok = false;
          }
        }
      }
    }
    if (!ok) {
      continue;
    }
    // 正直者を数える
//    ll tmp = __builtin_popcount(i);
    ll tmp = 0;
    rep(j, n) {
      if (i >> j & 1) {
        tmp++;
      }
    }
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}
