#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  int n, m; cin >> n >> m;
  vl s(n), t(m); ina(s,n); ina(t,m);
  vvl dp(n+1, vl(m+1,0));
  rep(i,n+1) dp[i][0] = 1;
  rep(j,m+1) dp[0][j] = 1;
  REP(i,1,n+1) {
    REP(j,1,m+1) {
      dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
      if (s[i-1] == t[j-1]) {
        dp[i][j] += dp[i-1][j-1];
      }
      dp[i][j] = (dp[i][j] + MOD) % MOD;
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
