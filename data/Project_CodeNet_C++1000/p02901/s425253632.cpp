#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int N = 5000, inf = 0x3f3f3f3f;

int dp[N];

signed main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    int c[N], key[N];
    for (int i = 0; i < m; ++i)
    {
        int sz;
        cin >> c[i] >> sz;
        for (int j = 0; j < sz; ++j)
        {
            int x;
            cin >> x;
            key[i] += (1 << (x - 1));
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dp[i | key[j]] = min(dp[i | key[j]], dp[i] + c[j]);
        }
    }
    cout << (dp[(1 << n) - 1] == inf ? -1 : dp[(1 << n) - 1]);
    return 0;
}

/* input

*/