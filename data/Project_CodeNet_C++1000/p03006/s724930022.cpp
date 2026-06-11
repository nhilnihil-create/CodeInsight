#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = INF;
  cin >> n;
  if (n == 1) {
    puts("1");
    return 0;
  }
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int p = x[i] - x[j];
      int q = y[i] - y[j];
      int cnt = 0;
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
          if (k == l) continue;
          if (x[l] == x[k] + p && y[l] == y[k] + q) cnt++;
        }
      }
      ans = min(ans, n - cnt);
    }
  }

  cout << ans << endl;
  return 0;
}
