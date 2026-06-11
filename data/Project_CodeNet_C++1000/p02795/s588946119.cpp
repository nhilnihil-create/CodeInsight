#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT

using namespace std;

signed main() {
  ll H, W, N, ans = 0;
  cin >> H >> W >> N;
  while (N > 0) {
    if (H > W) {
      N -= H;
      W--;
    } else {
      N -= W;
      H--;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
