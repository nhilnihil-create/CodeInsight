#include <bits/stdc++.h>
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, a, n) for (ll i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll l, r;
  cin >> l >> r;
  int ans = 1e15;
  rep(i, l, min(l + 2020, r)) {
    rep(j, l + 1, min(l + 2020, r + 1)) {
      int x = i % 2019;
      int y = j % 2019;
      ans = min(ans, (x * y) % 2019);
    }
  }

  cout << ans << endl;
}
