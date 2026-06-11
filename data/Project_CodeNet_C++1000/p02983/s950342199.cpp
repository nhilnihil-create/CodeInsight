#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll l, r;
  cin >> l >> r;
  ll ans = 2018LL * 2018LL;
  for (ll i = 0; i < min(2019LL, r - l); i++) {
    ll in = (l + i) % 2019;
    for (ll j = 1; j < min(2019LL, r - l) - i + 1; j++) {
      ll jn = (in + j) % 2019;
      ll calc = in * jn % 2019;
      ans = min(ans, calc);
    }
  }

  cout << ans << endl;
  return 0;
}