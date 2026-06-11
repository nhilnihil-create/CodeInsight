#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define MOD 1000000007

int main()
{
  string n;
  cin >> n;

  vector<ll> dp = {0, 1};
  dp.resize(2, 0);
  for (auto i = 0; i < n.size(); i++)
  {
    ll d = n[i] - '0';
    auto a = min(dp[0] + d, dp[1] + 10 - d);
    auto b = min(dp[0] + d + 1, dp[1] + 9 - d);
    dp[0] = a;
    dp[1] = b;
  }

  cout << dp[0] << endl;

  return 0;
}
