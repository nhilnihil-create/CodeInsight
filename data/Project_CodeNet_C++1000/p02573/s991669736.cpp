#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// bfsで解くバージョン
int main()
{
    int n, m;
    cin >> n >> m;

    Graph G(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 s をスタートとした探索
    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;
    int ans = 0;
    for (int v = 0; v < n; ++v)
    {
        if (dist[v] != -1)
            continue; // v が探索済みならスルー
        dist[v] = 0, que.push(v);
        int count = 1;
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            for (auto nv : G[v])
            {
                if (dist[nv] == -1)
                {
                    dist[nv] = dist[v] + 1;
                    ++count;
                    que.push(nv);
                }
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;

    return 0;
}
