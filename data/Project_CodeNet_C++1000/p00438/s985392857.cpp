#include <cstdio>

#define REP(i, n) for (i = 0; i < (n); i++)
#define FOR(i, a, b) for (i = (a); i < (b); i++)

using namespace std;

int main()
{
  int a, b, i, j;

  while (scanf("%d%d", &a, &b), (a + b)){
    int n, x, y;
    int dp[20][20] = {0};
    bool flag[20][20] = {false};
    dp[0][1] = 1;

    scanf("%d", &n);
    REP(i, n){
      scanf("%d%d", &x, &y);
      flag[x][y] = true;
    }
    FOR(i, 1, a + 1){
      FOR(j, 1, b + 1){
        if (!flag[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    printf("%d\n", dp[a][b]);
  }
}