#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll l, r;
  cin >> l >> r;
  r = min(r, l + 2019);
  int ans = 2019;
  for (ll i = l; i < r; i++) {
    for (ll j = i+1; j < r+1; j++) {
      int temp = i * j % 2019;
      ans = min(ans, temp);
    }
  }
  cout << ans << '\n';
  return 0;
}