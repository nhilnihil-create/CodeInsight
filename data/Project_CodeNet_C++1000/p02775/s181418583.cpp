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

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  reverse(ALL(s));
  ll n = SZ(s);
  const ll INF = 1e18;
  vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
  dp[0][0] = 0;
  REP(i, n) {
    ll c = s[i] - '0';
    chmin(dp[i + 1][0], dp[i][0] + c);
    chmin(dp[i + 1][1], dp[i][0] + 10 - c);
    chmin(dp[i + 1][0], dp[i][1] + c + 1);
    chmin(dp[i + 1][1], dp[i][1] + 9 - c);
  }
  dp[n][1]++;
  // REP(i, n + 1) {
  //   REP(j, 2) { cout << dp[i][j] << " \n"[j == 1]; }
  // }
  cout << min(dp[n][0], dp[n][1]) << endl;
}