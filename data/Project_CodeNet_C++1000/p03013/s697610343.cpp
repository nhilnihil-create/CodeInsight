#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int mod = 1000000007;
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> dp(n + 2, 0);
  for (int i = 0; i < m; i++)
  {
    int buf;
    cin >> buf;
    a[buf] = 1;
  }
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i])
    {
      continue;
    }

    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << endl;
}
