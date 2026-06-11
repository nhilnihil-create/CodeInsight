#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  int n, m; cin >> n >> m;
  V s(n), t(m);
  rep(i, n) cin >> s[i];
  rep(i, m) cin >> t[i];


  VVll dp(n+1, Vll(m+1));

  rep(i, n+1) dp[i][0] = 1;
  rep(i, m+1) dp[0][i] = 1;

  rep(i, n) rep(j, m) {
    dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
    if (s[i] != t[j]) dp[i+1][j+1] -= dp[i][j];
    dp[i+1][j+1] = (dp[i+1][j+1] + MOD) % MOD;
  }
  cout << dp[n][m] << endl;
  return 0;
}
