#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;

vector<P> to[100005][3];
bool used[100005][3];
int dist[100005][3];

void bfs(int x) {
    queue<P> q;
    used[x][0] = true;
    dist[x][0] = 0;
    q.push(P(x, 0));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto e: to[p.first][p.second]) {
            if (used[e.first][e.second]) continue;
            q.push(e);
            used[e.first][e.second] = true;
            dist[e.first][e.second] = dist[p.first][p.second] + 1;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u][0].emplace_back(v, 1);
        to[u][1].emplace_back(v, 2);
        to[u][2].emplace_back(v, 0);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    bfs(s);

    int ans = dist[t][0]/3;
    if (ans==0) ans = -1;
    
    cout << ans << endl;
    return 0;
}
