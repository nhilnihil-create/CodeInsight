#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

#define rep(i, n) for (int i = 1; i <= n; ++i)

using P = std::pair<int, int>;

constexpr int MAX = 1e5 + 10;

int n, m;
std::vector<int> g[MAX];

bool used[3][MAX];

int d[3][MAX];

int main()
{

    std::cin >> n >> m;

    rep(i, m)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }

    std::queue<P> que;

    int s, t;
    std::cin >> s >> t;

    d[0][s] = 0;
  	used[0][s]=1;
    que.emplace(0, s);

    while (!que.empty())
    {

        int mod, x;
        std::tie(mod, x) = que.front();
        que.pop();

        if (mod == 0 && x == t)
            break;

        int nmod = (mod + 1) % 3;

        for (int y : g[x])
        {
            if (!used[nmod][y])
            {
                que.emplace(nmod, y);
                d[nmod][y] = d[mod][x] + 1;
              	used[nmod][y]=1;
            }
        }
    }

    if (!used[0][t])
        std::cout << -1 << std::endl;
    else
    {
        std::cout << d[0][t] / 3 << std::endl;
    }

    return 0;
}
