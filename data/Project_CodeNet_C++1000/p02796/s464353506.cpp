#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef std::pair<ll, ll> PLL;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT

using namespace std;

signed main() {
  ll N;
  cin >> N;
  vector<PLL> v;
  rep(i, N) {
    ll a, b;
    cin >> a >> b;
    v.emplace_back(a-b, a+b);
  }
  sort(v.begin(), v.end(), [](const PLL &x, const PLL &y) {
      return x.second < y.second;
      });
  ll ans = 0, R = -1e18;
  for (auto b : v) {
    if (R <= b.first) {
      R = b.second;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
