#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(n+1, vector<int>(2, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; i++) {

    if (s[i] == '0') {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
    } else {
      dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
    }
    if (s[i] == '0') {
      (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
    } else {
      (dp[i + 1][0] += dp[i][0] * 2 % mod) %= mod;
      (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
    }
  }
  cout << (dp[n][0] + dp[n][1]) % mod << endl;
  return 0;
}