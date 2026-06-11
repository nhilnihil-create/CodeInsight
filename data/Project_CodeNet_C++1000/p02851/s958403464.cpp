#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }
  vector<ll> s(n + 1, 0);
  REP(i, n) { s[i + 1] = s[i] + a[i]; }
  map<ll, vector<ll>> mp;
  REP(i, n + 1) { mp[(s[i] - i + 1000 * k) % k].push_back(i); }
  ll ans = 0;
  for (auto& kv : mp) {
    vector<ll> v = kv.second;
    REP(i, SZ(v)) {
      ll x = max(0LL, upper_bound(ALL(v), v[i] + k - 1) - v.begin() - i - 1);
      ans += x;
    }
  }
  cout << ans << endl;
}