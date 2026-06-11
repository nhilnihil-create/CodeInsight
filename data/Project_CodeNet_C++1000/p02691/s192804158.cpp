/*input
32
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> b(n), c(n);
  rep(i, n) {
    b[i] = -a[i]-i;
    c[i] = a[i]-i;
  }
  sort(c.begin(), c.end());
  ll ans = 0;
  rep(i, n) {
    ll now = upper_bound(c.begin(), c.end(), b[i])
      -lower_bound(c.begin(), c.end(), b[i]);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}