#include <iostream>
#include <algorithm>

constexpr int MAX = 2010;

using ll = long long int;

constexpr ll mod = 1e9 + 7;

ll ct[MAX][MAX];

int s[MAX], t[MAX];

int main()
{

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];

    for (int i = 1; i <= m; ++i)
        std::cin >> t[i];

    for (int i = 0; i <= n; ++i)
        ct[i][0] = 1;

    for (int i = 0; i <= m; ++i)
        ct[0][i] = 1;

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            ct[x][y] = (ct[x - 1][y] + ct[x][y - 1] - ct[x - 1][y - 1]+mod) % mod;

            if (s[x] == t[y])
                ct[x][y] = (ct[x][y] + ct[x - 1][y - 1]) % mod;
        }
    }

    std::cout << ct[n][m] << std::endl;

    return 0;
}
