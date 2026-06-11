#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define REP(i, n) for(int i = 0; (i) < (n); ++(i))
#define FOR(i, n) for(int i = 1; (i) <= (n); ++(i))
#define dump(x) cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9 + 7;
// const lint LINF = 1e18;
const double eps = 0.000000001;  //もとの値の10^(-16)まで

using namespace std;

// typedef pair<int, int> P;
// priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
// cout << fixed << setprecision(10) << ans << endl;

int n, k;
int h[400];
int dp[400][400][400];  // i列目、j回、その高さ のとき、何回で塗り終わるか

signed main() {
  cin >> n >> k;
  h[0] = 0;
  REP(i, n) {
    cin >> h[i + 1];
  }
  h[n + 1] = 0;
  REP(i, n + 1) {
    REP(j, n + 1) {
      REP(l, n + 1) {
        dp[i][j][l] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  REP(i, n + 1) {
    REP(j, n + 1) {
      REP(l, n + 1) {
        dp[i + 1][j][i + 1] = min(dp[i + 1][j][i + 1], dp[i][j][l] + max((int)0,h[i + 1] - h[l]));
        dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][l]);
      }
    }
  }
  int ans = INF;
  REP(j, k + 1) {
    REP(l, n + 1) {
      ans = min(ans, dp[n][j][l]);
    }
  }

  cout << ans << endl;
  return 0;
}