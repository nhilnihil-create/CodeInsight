#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    bool visited[n] = {0};
    int distance[n] = {};
    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int s = q.front(); q.pop();
        for(int u :adj[s])
        {
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = s;
            q.push(u);
        }
    }
    for(bool b :visited)
    {
        if(b == false)
        {
            cout << "No" << endl;
            break;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i<n; i++)
    {
        cout <<  distance[i]+1 << endl;
    }

}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
