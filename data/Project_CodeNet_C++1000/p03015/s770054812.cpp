// https://atcoder.jp/contests/abc129/tasks/abc129_e

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int L_MAX = 100'001;
const int MOD = 1e9+7;

char L[L_MAX + 1];

int N;
int dp[L_MAX + 1][2];

void solve() {
  N = strlen(L);
  dp[0][0] = 1;
  REP(i, N) {
    int d = L[i] - '0';
    REP(smaller, 2) REP(j, smaller || d ? 3 : 1) {
      int smaller2 = smaller || j < d;
      dp[i + 1][smaller2] = (dp[i + 1][smaller2] + dp[i][smaller]) % MOD;
    }
  }
  // DUMP2D(dp, N + 1, 2);
  int ans = (dp[N][0] + dp[N][1]) % MOD;
  printf("%d\n", ans);
}

void input() {
  scanf("%s", L);
}

int main() {
  input();
  solve();
  return 0;
}
