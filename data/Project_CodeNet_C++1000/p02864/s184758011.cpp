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
  vector<ll> h(n + 1);
  h[0] = 0;
  REP(i, n) { cin >> h[i + 1]; }

  const ll INF = 1e15;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 3, INF));
  dp[0][0] = 0;

  FOR(i, 1, n + 1) FOR(j, 1, n - k + 1) {
    ll t = INF;
    REP(l, i) { t = min(t, dp[l][j - 1] + max(h[i] - h[l], 0LL)); }
    dp[i][j] = t;
  }
  ll ans = INF;
  REP(i, n + 1) { ans = min(ans, dp[i][n - k]); }
  cout << ans << endl;
}