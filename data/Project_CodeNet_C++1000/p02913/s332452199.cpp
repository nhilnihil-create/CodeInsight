#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int r = n - 1; r > 0; r--)
    for (int l = r - 1; l >= 0; l--)
      if (s[r] == s[l])
      {
        if (r == n - 1)
          dp[l][r] = 1;
        else
          dp[l][r] = dp[l+1][r+1] + 1;
        ans = max(ans, min(dp[l][r], r - l));
      }
  cout << ans << endl;
  return 0;
}