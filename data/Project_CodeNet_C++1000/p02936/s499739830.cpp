#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<int> ans(n, 0);
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    dist[0] = ans[0];
    que.push(0);
    while (!que.empty())
    {
        int v = que.front();que.pop();

        for (int nv : G[v])
        {
            if(dist[nv] != -1)continue;

            dist[nv] = dist[v] + ans[nv];
            que.push(nv);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(dist[i] == -1)cout << 0 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}