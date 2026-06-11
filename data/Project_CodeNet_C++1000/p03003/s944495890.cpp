
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

const int MOD = 1000000007;

int ss[2000+10];
int ts[2000+10];

ll dp[2010][2010];

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) {
    scanf("%d", &ss[i]);
  }
  REP(i, m) {
    scanf("%d", &ts[i]);
  }

  dp[0][0] = 1;
  REP(i, n+1) REP(j, m+1) {
    if(i > 0) {
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
    }
    if(j > 0) {
      dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
    }
    if(i > 0 && j > 0) {
      dp[i][j] = (dp[i][j] + MOD - dp[i-1][j-1]) % MOD;
      if(ss[i-1] == ts[j-1]) {
        dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
      }
    }
  }
  cout << dp[n][m] << endl;
  
  return 0;
}
