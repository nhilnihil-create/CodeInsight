#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, t;

    std::cin >> n >> t;

    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i] >> b[i];
    }

    std::vector<std::vector<int>>
        d0(t, std::vector<int>(n + 1, 0)), d1(t, std::vector<int>(n + 2, 0));

    for (int i = 1; i <= t - 1; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            d0[i][j] = std::max(d0[i][j - 1], d0[i - 1][j]);

            if (i >= a[j])
                d0[i][j] = std::max(d0[i - a[j]][j - 1] + b[j], d0[i][j]);
        }
    }

    for (int i = 1; i <= t - 1; ++i)
    {
        for (int j = n; j >= 1; --j)
        {
            d1[i][j] = std::max(d1[i][j + 1], d1[i - 1][j]);

            if (i >= a[j])
                d1[i][j] = std::max(d1[i][j], d1[i - a[j]][j + 1] + b[j]);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= t - 1; ++j)
            ans = std::max(ans, b[i] + d0[j][i - 1] + d1[t - j - 1][i + 1]);
    }

    std::cout << ans << std::endl;

    return 0;
}
