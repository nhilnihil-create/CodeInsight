#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 303

int H[N];
long long dp[N][N];
void solve() {
  int n,k; scanf("%d %d",&n,&k);
  const long long inf = 2e18;
  for(int i=1;i<=n;++i) scanf("%d",&H[i]);
  for(int i=1;i<=n+1;++i) {
    for(int j=0;j<=k;++j) dp[i][j] = inf;
  }
  dp[0][0] = 0;
  for(int i=0;i<=n;++i) {
    for(int j=0;j<=k;++j) {
      for(int x=i+1;x<=n+1 && j + x-i-1<=k;++x) {
        int add = max(0,H[x]-H[i]);
        dp[x][j + x-i-1] = min(dp[x][j + x-i-1], dp[i][j] + max(0, H[x]-H[i]));
      }
    }
  }
  long long ret = dp[n+1][k];
  printf("%lld\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
