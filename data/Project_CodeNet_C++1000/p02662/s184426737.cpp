#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];
  ll MOD = 998244353;
  vector<ll> dp(s + 1, 0);
  dp[0] = 1;
  rep(i, n)
    for (int j=s; j>=0; j--)
    {
      if (j + a[i] <= s)
        dp[j+a[i]] = (dp[j+a[i]] + dp[j]) % MOD;
      dp[j] = dp[j] * 2 % MOD;
    }
  cout << dp[s] << endl;
}