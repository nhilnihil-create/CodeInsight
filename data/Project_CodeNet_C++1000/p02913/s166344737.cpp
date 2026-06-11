#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
constexpr int mod = 1e9+7;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j] && j - dp[i][j] > i) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) res = max(res, dp[i][j]);
  }
  cout << res << endl;
  return 0;
} 
