#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> a(n), b(n);
  rep(i, n)
    cin >> a[i] >> b[i];
  vector<vector<int>> dp1(n, vector<int>(t, 0));
  vector<vector<int>> dp2(n, vector<int>(t, 0));
  rep(i, n - 1)
    for (int j = 1; j < t; j++)
    {
      dp1[i+1][j] = max(dp1[i][j], dp1[i+1][j-1]);
      if (j >= a[i])
        dp1[i+1][j] = max(dp1[i+1][j], dp1[i][j-a[i]] + b[i]);
    }
  for (int i = n - 1; i > 0; i--)
    for (int j = 1; j < t; j++)
    {
      dp2[i-1][j] = max(dp2[i][j], dp2[i-1][j-1]);
      if (j >= a[i])
        dp2[i-1][j] = max(dp2[i-1][j], dp2[i][j-a[i]] + b[i]);
    }
  int ans = 0;
  rep(i, n)
    rep(j, t)
      ans = max(ans, b[i] + dp1[i][j] + dp2[i][t-j-1]);
  cout << ans << endl;
  return 0;
}