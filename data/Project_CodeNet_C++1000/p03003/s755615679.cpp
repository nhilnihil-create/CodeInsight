#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 2003
#define mod 1000000007

int dp[N][N];
int add(int x,int y) {
  int ret = x+y;
  if(ret>=mod) {
    ret -= mod;
  }
  if(ret<0) {
    ret += mod;
  }
  return ret;
}

int s[N],t[N];
void solve() {
  int n,m;scanf("%d %d",&n,&m);
  for(int i=0;i<n;++i) scanf("%d ", &s[i]);
  for(int i=0;i<m;++i) scanf("%d ", &t[i]);
  for(int i=n-1;i>=0;--i) {
    for(int j = m-1;j>=0;--j) {
      int tmp = 0;
      if(s[i]==t[j]) {
        tmp = dp[i+1][j+1] + 1;
      }
      dp[i][j] = add(dp[i+1][j],dp[i][j+1]);
      dp[i][j] = add(dp[i][j],-dp[i+1][j+1]);
      dp[i][j] = add(dp[i][j],tmp);
    }
  }
  int ret = add(dp[0][0],1);
  printf("%d\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
