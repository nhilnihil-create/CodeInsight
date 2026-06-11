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
  ll k, q;
  cin >> k >> q;
  vector<ll> d2(k);
  REP(i, k) { cin >> d2[i]; }
  while (q--) {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> d(k), s(k + 1, 0);
    REP(i, k) {
      d[i] = d2[i] % m;
      if (d[i] == 0) {
        d[i] = m;
      }
      s[i + 1] = s[i] + d[i];
    }
    n--;
    ll t = x + (n / k) * s[k] + s[n % k];
    ll ans = n - (t / m - x / m);
    cout << ans << endl;
  }
}