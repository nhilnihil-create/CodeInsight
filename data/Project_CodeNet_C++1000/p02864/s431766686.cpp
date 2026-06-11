#include <bits/stdc++.h>
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, irep, _rep)(__VA_ARGS__)
#define rep1(...) GET_REP(__VA_ARGS__, irep1, _rep1)(__VA_ARGS__)
#define _rep(i, n) irep (i, 0, n)
#define _rep1(i, n) irep1(i, 1, n)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define irep1(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(X, x) for (auto &&X : x)
#define all(x) begin(x), end(x)
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
  #define debug(x) cout << #x " => " << (x) << endl
#else
  #define debug(x) 0
#endif
using lint = long long;
constexpr int    INF  = 1 << 28;
constexpr lint   INFL = 1LL << 60;
constexpr int    MOD  = (int)1e9 + 7;
constexpr double EPS  = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

vector<vector<vector<lint>>> dp;
int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep (i, n) cin >> h[i];
  h.insert(h.begin(), 0);
  // dp[i個目まで見た][現在の高さがh[j]][l個選んだ]
  dp.assign(n + 1, vector<vector<lint>>(n + 1, vector<lint>(n + 1, LLONG_MAX)));
  dp[0][0][0] = 0;
  rep (i, n) {
    rep (j, i + 1) {
      rep (l, i + 1) {
        if (l > k) break;
        lint now = dp[i][j][l];
        if (now == LLONG_MAX) continue;
        dp[i + 1][j][l + 1] = min(dp[i + 1][j][l + 1], now);
        dp[i + 1][i + 1][l] = min(dp[i + 1][i + 1][l], now + max(0, h[i + 1] - h[j]));
      }
    }
  }
  lint mini = LLONG_MAX;
  rep (i, n + 1) {
    rep (j, k + 1) {
      lint tmp = dp[n][i][j];
      mini = min(mini, tmp);
    }
  }
  cout << mini << endl;
  return 0;
}