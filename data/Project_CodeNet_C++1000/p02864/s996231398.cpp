#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e12;
const long double EPS = 1e-10;

int main() {
  ll n, k ;
  cin >> n >> k ;
  vector<ll> h(n + 1, 0);
  FOR(i, 1, n + 1) cin >> h[i];
  ll dp[n - k + 1][n + 1];
  rep(i, n - k + 1) {
    rep(j, n + 1) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  rep(i, n){
    rep(j, n - k){
      rep(l, i + 1){
        dp[j + 1][i + 1]=min(dp[j + 1][i + 1],dp[j][l]+max(0LL,h[i + 1] - h[l]));
      }
    }
  }

  ll ans = INF;
  rep(i, n + 1){
    ans = min(ans,dp[n - k][i]);
  }
  cout << ans << endl;
  
  return 0;
}