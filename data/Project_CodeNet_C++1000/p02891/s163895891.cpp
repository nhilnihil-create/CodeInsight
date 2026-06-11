#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll cnt = 1;
  int n = (int)s.size();
  rep(i, 0, n - 1) {
    if (s[i] == s[i + 1])
      ++cnt;
    else
      break;
  }
  if (cnt == n) {
    cout << cnt * k / 2 << '\n';
    return 0;
  }

  ll ans = 0;
  rep(i, 0, n - 1) {
    if (s[i] == s[i + 1]) {
      ans++;
      s[i + 1] = '.';
    }
  }
  ans *= k;
  if (s[0] == s[n - 1] && cnt % 2 == 1) ans += k - 1;
  cout << ans << '\n';
  return 0;
}