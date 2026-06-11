#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

signed main() {
  string N;
  cin >> N;

  int keta = (int)N.size();

  //dp[i][fg] = i桁目までの支払いで最小の札数と、余分に支払っているかどうか
  vector<vector<int>> dp(keta+10, vector<int>(2));
  dp[0][1] = 1;
  for( int i = 0; i < keta; i++ ){
    int num = N[i]-'0';
    dp[i+1][0] = min(dp[i][0]+num, dp[i][1]+(10-num));
    dp[i+1][1] = min(dp[i][0]+num+1, dp[i][1]+(10-num-1));
  }
  cout << dp[keta][0]<< endl;
}