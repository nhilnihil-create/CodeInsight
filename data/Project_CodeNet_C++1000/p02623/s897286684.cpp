#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  vector<ll> sum_a(n + 1, 0), sum_b(m + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum_a[i + 1] += sum_a[i] + a[i];
    // cout << sum_a[i + 1] << '\n';
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    sum_b[i + 1] += sum_b[i] + b[i];
    // cout << sum_b[i + 1] << '\n';
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (sum_a[i] > k) break;
    int cnt = 0;
    for (int j = m; j >= 0; j--) {
      // cout << i << ' ' << j << '\n';
      // cout << sum_a[i] + sum_b[j] << '\n';
      if (sum_a[i] + sum_b[j] > k) continue;
      m = j;
      cnt = i + j;
      break;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}
