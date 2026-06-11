/*input
3
101 9901 999999000001
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  const ll M = 1e18;
  rep(i, n) {
    if (a[i] > M/ans) {
      cout << -1  << endl;
      return 0;
    }
    ans *= a[i];
  }
  cout << ans << endl;
}