#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  ll k, q;
  cin >> k >> q;
  vector<ll> d(k);
  REP(i, k) cin >> d[i];

  REP(qi, q) {
    ll n, x, m;
    cin >> n >> x >> m;
    ll last = x, eq = 0;
    REP(i, k) {
      ll cnt = (n - 1) / k;
      if ((n - 1) % k > i) ++cnt;
      last += cnt * (d[i] % m);
      if ((d[i] % m) == 0) eq += cnt;
    }
    ll ans = n - 1 - (last / m - x / m) - eq;
    cout << ans << endl;
  }
  return 0;
}