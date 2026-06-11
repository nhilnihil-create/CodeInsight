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
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];
  vector<vector<int>> dp(t + 1, vector<int>(2, 0));

  for (int i = 0; i < n; i++) {
    for (int j = t - 1; j >= 0; j--) {
      if (j + a[i] <= t) {
        dp[j + a[i]][0] = max(dp[j + a[i]][0], dp[j][0] + b[i]);
        dp[j + a[i]][1] = max(dp[j + a[i]][1], dp[j][1] + b[i]);
      }
      dp[j][1] = max(dp[j][1], dp[j][0] + b[i]);
    }
  }

  cout << dp[t - 1][1] << endl;
  return 0;
} 
