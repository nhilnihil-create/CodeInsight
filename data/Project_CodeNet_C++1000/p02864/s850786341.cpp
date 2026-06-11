#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int
main() {
 
  int n, k;
  cin>>n>>k;

  vector<ll> h(n+2, 0);
  for (int i=1; i<=n; i++) cin>>h[i];

  vector<vector<ll>> dp(n+2, vector<ll>(n+2, 1e18));
  for (int i=0; i<n+2; i++) dp[0][i] = 0;

  for (int end=1; end<=n+1; end++) 
    for (int level=0; level<=n; level++) {
      for (int i=0; i<=level; i++) {
        if (end-1-i < 0) continue;
        dp[end][level] = min(dp[end][level], dp[end-1-i][level-i] + max(0ll, h[end] - h[end-1-i]));
      }
    }

  cout<<dp[n+1][k]<<endl;
  return 0;
}
