#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if ((a + b) >= k) {
    cout << ((k >= a) ? a : k) << '\n';
    return;
  }
  ll ans = a - (k - (a + b));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
