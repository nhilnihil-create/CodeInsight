#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;

    vector<vector<int>> A(n);
    rep(i, n - 1)
    {
        A[i].emplace_back(i + 1);
        A[i + 1].emplace_back(i);
    }
    A[x].emplace_back(y);
    A[y].emplace_back(x);

    vector<int> ans(n, 0);
    // BFS のためのデータ構造
    for (int i = 0; i < n; ++i)
    {
        vector<int> dist(n, -1);
        queue<int> que;

        // initial state
        dist[i] = 0;
        que.push(i);

        // bfs
        while (!que.empty())
        {
            int v = que.front();
            if (v > i)
                ++ans[dist[v]];
            que.pop();

            for (int nv : A[v])
            {
                if (dist[nv] != -1)
                    continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    for (int i = 1; i < n; ++i)
        cout << ans[i] << endl;
}