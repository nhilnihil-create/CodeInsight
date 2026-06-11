#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vll = vector<ll>;
using vvll = vector<vll>;

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, k;
  cin >> n >> k;
  vll a(n);
  rep(i, n) {
    cin >> a[i];
  }

  vll s(n + 1);
  rep(i, n) {
    s[i + 1] = s[i] + a[i];
  }

  ll ans = 0;

  map<ll, vll> m;
  rep(i, n + 1) {
    ll mod = (s[i] - i) % k;

    auto it = upper_bound(all(m[mod]), i - k);
    ll idx = distance(m[mod].begin(), it);
    ans += m[mod].size() - idx;

    m[mod].push_back(i);
  }

  cout << ans << endl;

  return 0;
}
