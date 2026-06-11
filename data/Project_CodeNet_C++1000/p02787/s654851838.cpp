#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int h, n;

    std::cin >> h >> n;

    std::vector<int> a(n), b(n);

    int am = 0;

    rep(i, n)
    {
        std::cin >> a[i] >> b[i];
        am = std::max(am, a[i]);
    }
    am += h;

    constexpr int INF = 1e9;

    std::vector<int> d(am, INF);

    d[0] = 0;

    for (int i = 1; i < am; ++i)
    {
        rep(j, n)
        {
            if (i >= a[j])
                d[i] = std::min(d[i], b[j] + d[i - a[j]]);
        }
    }

    int ans = INF;

    for (int i = h; i < am; ++i)
    {
        ans = std::min(ans, d[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}