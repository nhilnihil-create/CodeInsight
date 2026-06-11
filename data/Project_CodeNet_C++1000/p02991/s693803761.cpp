#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N, M, S, T;
vector<P> G[200005][3];
int dist[200005][3];

int main() {
    cin >> N >> M;
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u][0].emplace_back(v, 1);
        G[u][1].emplace_back(v, 2);
        G[u][2].emplace_back(v, 0);
    }
    cin >> S >> T;
    --S, --T;
    rep(i,200005) rep(j,3) dist[i][j] = -1;
    queue<P> q;
    q.push(P(S,0));
    dist[S][0] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int u = cur.first;
        int mod = cur.second;
        for( auto child : G[u][mod]) {
            int v = child.first;
            int mv = child.second;
            if (dist[v][mv] != -1) continue;
            dist[v][mv] = dist[u][mod] + 1;
            q.push(P(v,mv));
        }
    }
    if (dist[T][0] == -1) cout << "-1" << endl;
    else cout << dist[T][0]/3 << endl;
}