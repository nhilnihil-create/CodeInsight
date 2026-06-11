#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= n; ++i)

int main()
{
    int n;
    ll k;
    std::cin >> n >> k;

    int m = 0;
    for (ll x = 1; x <= k; x *= 2)
    {
        ++m;
    }

    std::vector<std::vector<int>> vis(m, std::vector<int>(n + 1));

    rep(i, n)
    {
        std::cin >> vis[0][i];
    }

    rep(i, m - 1)
    {
        rep(j, n)
        {
            vis[i][j] = vis[i - 1][vis[i - 1][j]];
        }
    }

    ll x = 1;

    int ans = 1;

    rep(i, 60)
    {
        if (k & x)
            ans = vis[i - 1][ans];
        x *= 2;
    }

    std::cout << ans << std::endl;

    return 0;
}