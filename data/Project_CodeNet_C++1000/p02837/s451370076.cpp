#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<P>> v(n);
  rep(i, 0, n) {
    int c;
    cin >> c;
    rep(j, 0, c) {
      int x, y;
      cin >> x >> y;
      x--;
      v[i].push_back(make_pair(x, y));
    }
  }

  vector<vector<int>> pattern(1 << n);

  rep(i, 0, 1 << n) {
    rep(j, 0, n) {
      if (i >> j & 1)
        pattern[i].push_back(1);
      else
        pattern[i].push_back(0);
    }
  }

  int ans = 0;
  rep(i, 0, 1 << n) {
    bool flg = true;
    rep(j, 0, n) {
      if (pattern[i][j]) {
        for (auto vv : v[j]) {
          if (pattern[i][vv.first] != vv.second) {
            flg = false;
            break;
          }
        }
      }
      if (!flg)
        break;
    }
    if (flg) {
      chmax(ans, __builtin_popcount(i));
    }
  }

  cout << ans << endl;
}
