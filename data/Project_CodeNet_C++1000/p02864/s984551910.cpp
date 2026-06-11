#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, avail; cin >> n >> avail;
    fill(dp + 1, dp + n + 1, 1e9 * 305);
    
    vector<ll> block(n + 1);
    
    for (int i = 1; i <= n; ++i)
        cin >> block[i];
    
    for (int j = 1; j <= n - avail; ++j)
    {
        for (int k = n; k >= j; --k)
        {
            dp[k] = 1e9 * 305;
            
            for (int s = j - 1; s < k; ++s)
                dp[k] = min(dp[k], dp[s] + max(0ll, block[k] - block[s]));
        }
    }
    
    ll res(1e9 * 305);
    for (int x = n - avail; x <= n; ++x)
        res = min(res, dp[x]);
    
    cout << res;
}