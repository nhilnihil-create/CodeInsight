#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

constexpr int mod = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> broken(n + 1, false);
    rep(i, m)
    {
        int a;
        cin >> a;
        broken[a] = true;
    }
    vector<ll> dp(n + 1);
    dp[0] = 1;
  
    for (int i = 0; i < n; ++i)
    {
        if (!broken[i + 1])
        {
            dp[i + 1] += dp[i];
            dp[i + 1] %= mod;
        }
        if (i + 2 > n)
            continue;
        if (!broken[i + 2])
        {
            dp[i + 2] += dp[i];
            dp[i + 2] %= mod;
        }
    }

    cout << dp[n] << endl;
}