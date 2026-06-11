#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair <int,int> ii;
int n,m;
vector <int> adj[100002];
int vis[100002][3];
queue <ii> q;
void bfs(int s, int c) {
    q.push(ii(s,0));
    vis[s][0]=0;
    while (!q.empty()) {
        ii u=q.front();
        q.pop();
        for (int i:adj[u.x]) {
            if (!vis[i][(u.y+1)%3]) {
                q.push(ii(i,(u.y+1)%3));
                vis[i][(u.y+1)%3]=vis[u.x][u.y]+1;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s,t;
    cin >> n >> m;
    for (int i=0; i<m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cin >> s >> t;
    bfs(s,0);
    if (vis[t][0]) cout << vis[t][0]/3;
        else cout << -1;
}
