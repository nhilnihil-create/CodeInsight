#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int n;

int f(int x, int y)
{
    if (x > y)
        std::swap(x, y);
    return x * (n - 1 + n - x) / 2 + y - x - 1;
}

std::vector<std::vector<int>> g;

std::vector<int> d;

int dfs(int x)
{
    if (d[x] > 0)
        return d[x];

    //std::cerr << x << std::endl;

    int res = 0;

    for (int y : g[x])
        res = std::max(res, dfs(y));

    return d[x] = res + 1;
}

std::vector<bool> used;
std::set<int> set;

bool det(int x)
{

    for (int y : g[x])
    {
        if (set.count(y))
            return 1;
        if (!used[y])
        {
            set.insert(y);
            used[y] = 1;
            if (det(y))
                return 1;
            set.erase(y);
        }
    }

    return 0;
}

int main()
{

    std::cin >> n;

    int m = n * (n - 1) / 2;

    g.resize(m);
    d.resize(m, 0);

    rep(i, n)
    {
        int x;
        std::cin >> x;
        rep(j, n - 2)
        {
            int y;
            std::cin >> y;
            g[f(i, x - 1)].emplace_back(f(i, y - 1));
            x = y;
        }
    }

    /*rep(i, m)
    {
        for (int x : g[i])
            std::cerr << x << ' ';
        std::cerr << std::endl;
    }*/

    used.resize(m, 0);

    rep(i, m)
    {
        used[i] = 1;
        set.clear();
        set.insert(i);
        //std::cerr << i << std::endl;
        if (det(i))
        {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    int ans = 0;

    rep(i, m)
    {
        ans = std::max(ans, dfs(i));
    }

    std::cout << ans << std::endl;

    return 0;
}