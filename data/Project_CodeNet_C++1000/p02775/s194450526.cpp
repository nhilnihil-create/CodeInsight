#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n+1, vector<int>(2, INF));
  dp[0][0] = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + d);
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + 1);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 10 - d);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 9 - d);
  }
  int res = min(dp[n][0], dp[n][1] + 1);
  cout << res << endl;
  return 0;
}