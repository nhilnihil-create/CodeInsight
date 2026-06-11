#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;

const int INF = 1000*1000*1000;
const int N = 100;
const int W = 10000;
int n, m;
int dp[N+1][W+1];
int v[N+1], w[N+1];

int main() {
  int i, j;
  memset(dp, 0, sizeof(dp));
  scanf("%d%d ", &n, &m);
  for (i=1; i<=n; i++) scanf("%d%d ", v+i, w+i);
  for (i=1; i<=n; i++)
    for (j=0; j<=m; j++)
      if (j-w[i]<0)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);

  printf("%d\n", dp[n][m]);

  return 0;
}