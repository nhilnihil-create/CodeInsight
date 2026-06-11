#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  using ll = long long;
  ll l, r;
  cin >> l >> r;
  if (r - l > 2019) {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = 2019;
  for (ll i = l; i < r; i++) {
    for (ll j = l + 1; j <= r; j++) {
      ans = min(ans, i * j % 2019);
    }
  }
  cout << ans << '\n';
  return 0;
}
