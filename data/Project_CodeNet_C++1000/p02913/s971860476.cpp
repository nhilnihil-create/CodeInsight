#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int, int>;

int dp[5001][5001];

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i,n) {
    for (int j = i+1; j < n; ++j) {
      if (s[i] != s[j]) continue;
      if (i == j-dp[i][j]) continue;
      dp[i+1][j+1] = dp[i][j]+1;
      ans = max(ans, dp[i+1][j+1]);
    }
  }
  cout << ans << endl;
  return 0;
}