#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 200005
#define ll long long

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "
#else
#define debug(x) ;
#endif

int n, x, y;
vector<int> G[maxn];
queue<int> q;
int dx[maxn], dy[maxn];
int vis[maxn];
int ans[maxn];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);

    q.push(x);
    vis[x] = 1;
    dx[x] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < G[t].size(); i++) {
            int to = G[t][i];
            if (!vis[to]) {
                vis[to] = 1;
                dx[to] = dx[t] + 1;
                q.push(to);
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    q.push(y);
    vis[y] = 1;
    dy[y] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < G[t].size(); i++) {
            int to = G[t][i];
            if (!vis[to]) {
                vis[to] = 1;
                dy[to] = dy[t] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans[min(min(dy[i] + dy[j], dx[i] + dx[j]),j-i)]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}