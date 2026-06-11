#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

const ll MOD = 1000000007;
ll dp[100005][2];

int main() {
  string s;
  cin >> s;

  int n = s.size();

  dp[0][0] = 1;

  rep(i,n) {
    if (s[i] == '0') {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = 3*dp[i][1]%MOD;
    }
    else {
      dp[i+1][0] = 2*dp[i][0]%MOD;
      dp[i+1][1] = (dp[i][0]+3*dp[i][1])%MOD;
    }
  }
  cout << (dp[n][0] + dp[n][1])%MOD << endl;
  return 0;
}
