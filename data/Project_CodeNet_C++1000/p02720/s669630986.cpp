// https://atcoder.jp/contests/abc161/tasks/abc161_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int K_MAX = 1e5;
const int S_MAX = 9;

int K;

vector<vector<int>> dp;

int main() {
  cin >> K;

  dp = vector<vector<int>>(S_MAX + 1, vector<int>(10, 0));

  REP(j, 10) dp[0][j] = 1;
  REP(i, S_MAX) {
    REP(j, 10) {
      if (j > 0) dp[i + 1][j] += dp[i][j - 1];
      dp[i + 1][j] += dp[i][j];
      if (j < 9) dp[i + 1][j] += dp[i][j + 1];
    }
  }

  // DUMP2D(dp);

  int sum = 0;
  int i = 0;
  int j = 1;
  while (i <= S_MAX) {
    sum += dp[i][j];
    if (sum >= K) break;
    if (j < 9) {
      j++;
    } else {
      i++;
      j = 1;
    }
  }

  string ans = "";
  while (true) {
    // cout << "i=" << i << ", j=" << j << ", sum=" << sum << endl;
    ans += ('0' + j);
    if (i == 0) break;
    K = dp[i][j] - (sum - K);
    sum = 0;
    int i2 = i - 1;
    int j2;
    for (j2 = max(j - 1, 0); j2 <= min(j + 1, 9); j2++) {
      sum += dp[i2][j2];
      if (sum >= K) break;
    }
    i = i2;
    j = j2;
  }
  cout << ans << endl;
}
