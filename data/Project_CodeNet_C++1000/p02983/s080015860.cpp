#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll l, r;
  cin >> l >> r;
  ll ans = 1001001001001;
  for (ll i = l; i < r; i++) {
    for (ll j = i + 1; j <= r; j++) {
      ll tmp = (i * j) % 2019;
      ans = min(ans, tmp);
      if (ans == 0) break;
    }
    if (ans == 0) break;
  }
  cout << ans << endl;
  return 0;
}