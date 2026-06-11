#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> G(n);
    for (int i = 1; i <= n - 1; i++)
    {
        G[i - 1].push_back(i);
        G[i].push_back(i - 1);
    }
    x--;y--;
    G[x].push_back(y);
    G[y].push_back(x);

    vector<int> ans(n, 0);
/*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)G[i].size(); j++)cout << G[i][j] << " ";
        cout << endl;
    }
*/
    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, -1);
        queue<int> que;

        dist[i] = 0;
        que.push(i);

        while (!que.empty())
        {
            int v = que.front();
            que.pop();

            for (int nv : G[v])
            {
                if(dist[nv] != -1)continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        
        for (int j = i; j < n; j++)
        {
            ans[dist[j]]++;
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    
}