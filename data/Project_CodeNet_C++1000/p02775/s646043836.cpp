#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[1000005][2];
const ll INF = 1e9;

int main() {
  // 一桁目から桁dp、dp[i][j]：i桁目まで決めた時の最小値、繰り上がりが起きているならj=1
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  S += '0';
  int N = sz(S);
  rep(i, N+1) rep(j, 2) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i, N) rep(j, 2) {
    rep(a, 10) {
      // aはその桁で払うお金、bはお釣り
      int cur = S[i] - '0';
      int ni = i+1, nj = 0;
      cur += j; // 繰り上がり
      int b = a - cur;
      if (b < 0) {
        nj = 1;
        b += 10;
      }
      dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
    }
  }
  cout << dp[N][0] << '\n';
  return 0;
}