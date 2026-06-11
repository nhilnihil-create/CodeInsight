// https://atcoder.jp/contests/abc130/tasks/abc130_e

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 2*1e3;
const int M_MAX = 2*1e3;
const int S_I_MAX = 1e5;
const int T_I_MAX = 1e5;
const int MOD = 1e9+7;

int N, M;
int S[N_MAX];
int T[M_MAX];

int dp[N_MAX + 1][M_MAX + 1];

void solve() {
  REP(i, N + 1) dp[i][0] = 1;
  REP(j, M + 1) dp[0][j] = 1;
  REP(i, N) REP(j, M) {
    dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
    if (S[i] != T[j]) {
      dp[i + 1][j + 1] = (dp[i + 1][j + 1] + MOD - dp[i][j]) % MOD;
    }
  }
  printf("%d\n", dp[N][M]);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", S + i);
  REP(i, M) scanf("%d", T + i);
}

int main() {
  input();
  solve();
  return 0;
}
