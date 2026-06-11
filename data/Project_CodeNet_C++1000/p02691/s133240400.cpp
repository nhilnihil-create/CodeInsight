#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> sum_cnt(n), diff_cnt(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i + 1 + a < n) sum_cnt[i + 1 + a]++;
    if (i + 1 - a > 1) diff_cnt[i + 1 - a]++;
  }
  ll ans = 0;
  for (int i = 2; i < n; i++) {
    ans += sum_cnt[i] * diff_cnt[i];
  }
  cout << ans << '\n';
  return 0;
}
