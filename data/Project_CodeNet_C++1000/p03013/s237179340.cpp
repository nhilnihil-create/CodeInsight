#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
const int MOD = 1e9 + 7;
int dp[100010];
int main() {
  int n, m;
  cin >> n >> m;
  rep(i,m) {
    int a; cin >> a;
    dp[a] = -1;
  }
  dp[0] = 1;
  if (dp[1] == 0) dp[1] = 1;
  //if (dp[1] == 1 && dp[2] == 0) dp[2] = 2;  
  for (int i = 2; i <= n; i++)
  {
    if (dp[i] == -1) continue;
    dp[i] = max(dp[i-1],0) + max(dp[i-2],0);
    
    //if (dp[i-1] !=-1 && dp[i-2] != -1) dp[i] += dp[i-2];
    dp[i] %= MOD;
  }
  cout << dp[n] << endl;
  return 0;
}