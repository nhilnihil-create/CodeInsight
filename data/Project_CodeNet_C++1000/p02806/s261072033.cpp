#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v)                                                            \
  do {                                                                         \
    x = max(x, v);                                                             \
  } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  vector<pair<string, ll>> v(N);
  rep(i, N) { cin >> v[i].first >> v[i].second; }
  string s;
  cin >> s;
  ll i = 0;
  while (v[i].first != s)
    i++;
  i++;
  ll ans = 0;
  while (i < N) {
    ans += v[i].second;
    i++;
  }
  cout << ans << endl;
  return 0;
}
