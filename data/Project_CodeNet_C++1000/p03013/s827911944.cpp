#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    int n, m, tmp;
    cin >> n >> m;

    vector<ll> dp(n + 1), a(n + 1, 1);

    for(int i = 0; i < m; ++i)
    {
        cin >> tmp;
        a[tmp] = 0;
    }

    dp[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j <= min(n, i + 2); ++j)
        {
            if(a[j])
            {
                dp[j] += dp[i];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}