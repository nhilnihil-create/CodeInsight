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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> x(n, vector<int>(n - 1)), y(n, vector<int>(n - 1));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i]; j++) {
      cin >> x[i][j] >> y[i][j];
      x[i][j]--;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < 1 << n; bit++) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (bit >> i & 1) {
        for (int j = 0; j < a[i]; j++) {
          if ((bit >> x[i][j] & 1) ^ y[i][j]) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
    }
    if (ok) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << '\n';
  return 0;
}