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
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 998244353;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

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
      i++;
    }
  }
  ans *= k;
  if (s[0] == s[n - 1]) {
    ll tnc = 1;
    while (s[n - tnc - 1] == s[n - 1]) ++tnc;
    ans -= (k - 1) * (cnt / 2 + tnc / 2 - (cnt + tnc) / 2);
  }
  cout << ans << '\n';
  return 0;
}