#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int mx = 40;
  vector<vector<int>> ex(mx);
  for (int i = 0, a, a_; i < n; i++) {
    cin >> a;
    a_ = a;
    int cnt = 0;
    while (a > 0) {
      a /= 2;
      cnt++;
    }
    ex[cnt].emplace_back(a_);
  }
  debug(ex);
  for (int i = mx - 1; i > 0 && m > 0; i--) {
    if ((int)ex[i].size() <= m) {
      for (auto&& e : ex[i]) {
        e /= 2;
        ex[i - 1].emplace_back(e);
        e = 0;
      }
      m -= (int)ex[i].size();
    } else {
      sort(ex[i].begin(), ex[i].end(), greater<int>());
      for (int j = 0; j < m; j++) {
        ex[i][j] /= 2;
      }
      m = 0;
    }
    debug(i, m);
    debug(ex);
  }
  long long ans = 0;
  for (int i = 0; i < mx; i++) {
    for (auto&& e : ex[i]) {
      ans += e;
    }
  }
  cout << ans << '\n';
  return 0;
}