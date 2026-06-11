#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= (n); ++i)

constexpr int INF = 1e9;

int main()
{
    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> d(m + 1, std::vector<int>(1 << n, INF));

    std::vector<int> c(m + 1);

    std::vector<int> a(m + 1);

    rep(i, m)
    {
        int b;
        std::cin >> a[i] >> b;
        int x, y = 0;
        rep(j, b)
        {
            std::cin >> x;
            y += 1 << (x - 1);
        }
        c[i] = y;
    }

    for (int i = 0; i <= m; ++i)
        d[i][0] = 0;

    auto diff = [](int a, int b) {
        int x = 1;
        for (int i = 0; i < 12; ++i)
        {
            if ((a & x) && (b & x))
                a -= 1 << i;

            x *= 2;
        }
        return a;
    };

    for (int i = 1; i < (1 << n); ++i)
    {
        rep(j, m)
        {
            d[j][i] = std::min(d[j - 1][i], a[j] + d[j - 1][diff(i, c[j])]);
            int x = 1;
            for (int k = 0; k < 12; ++k)
            {
                if (i & x)
                    d[j][i - x] = std::min(d[j][i - x], d[j][i]);
                x *= 2;
            }
        }
    }

    /*for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j <= m; ++j)
            std::cerr << d[j][i] << ' ';
        std::cerr << std::endl;
    }*/

    std::cout << ((d[m][(1 << n) - 1] == INF) ? -1 : d[m][(1 << n) - 1]) << std::endl;

    return 0;
}