#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
#define mod 1000000007

int N, K, H[400];
ll dp[400][400];
// dp[i][j] =
// for k = i+1 to N min of
//   dp[k][j-1]+max(0, H[i]-H[k])
// ans = min(dp[i][N-K]) over i

int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  cin >> N >> K;
  for(int i = 1;i <= N;i++) {
    cin >> H[i];
  }

  for(int j = 1;j <= N;j++) {
    for(int i = N;i > 0;i--) {
      if(j == 1) {
        dp[i][j] = H[i];
        continue;
      }
      dp[i][j] = 1e12;
      for(int k = i+1;k <= N;k++) {
        dp[i][j] = min(dp[i][j], dp[k][j-1]+max(0, H[i]-H[k]));
      }
    }
  }

  ll ans = 1e12;
  for(int i = 1;i <= N;i++) {
    ans = min(ans, dp[i][N-K]);
  }

  cout << ans << endl;

  return 0;
}
