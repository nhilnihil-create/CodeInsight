#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> to[100005];
int dist[100005][3];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    rep(i,n)rep(j,3) dist[i][j] = INF;
    dist[s][0] = 0;
    queue<P> q;
    q.emplace(s,0);
    while (!q.empty()) {
        int v = q.front().first, id = q.front().second;
        q.pop();
        int d = dist[v][id];
        int nid = (id+1)%3;
        for (int u : to[v]) {
            if (dist[u][nid] <= d+1) continue;
            dist[u][nid] = d+1;
            q.emplace(u,nid);
        }
    } 
    if (dist[t][0] == INF) {
        cout << -1 << endl;
        return 0;
    }
    dist[t][0] /= 3;
    cout << dist[t][0] << endl;
    return 0;
}