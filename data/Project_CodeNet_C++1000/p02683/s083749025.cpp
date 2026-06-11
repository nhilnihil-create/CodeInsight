#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) {
      cin >> a[i][j];
    }
  }
  int ans = (int)1e9;
  rep(bit, 1 << n) {
    int cost = 0;
    vector<int> u(m, 0);
    rep(i, n) {
      if (bit & 1 << i) {
        cost += c[i];
        rep(j, m) {
          u[j] += a[i][j];
        }
      }
    }
    bool ok = true;
    rep(i, m) {
      if (u[i] < x) {
        ok = false;
        break;
      }
    }
    if (ok) ans = min(ans, cost);
  }
  if (ans == (int)1e9) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}
