#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

ll N, ans;
ll a[200000];
ll l[200000];
ll r[200000];

signed main() {
  cin >> N;
  rep(i, N + 1)
    cin >> a[i];
  l[N] = r[N] = a[N];
  for (ll i = N - 1; i >= 0; i--) {
    l[i] = (l[i + 1] + 1)/ 2 + a[i];
    r[i] = r[i + 1] + a[i];
  }
  if (1 < l[0] || r[0] < 1) {
    cout << -1 << endl;
    return 0;
  }
  ll node = 1;
  for (ll i = 0; i <= N; i++) {
    node = min(node, r[i]);
    ans += node;
    node -= a[i];
    node *= 2;
  }
  cout << ans << endl;
  return 0;
}
