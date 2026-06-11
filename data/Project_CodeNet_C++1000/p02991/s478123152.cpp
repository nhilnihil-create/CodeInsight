#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define rrep1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int>> g;

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    int s, t; cin >> s >> t;
    s--; t--;

    vector<vector<ll>> dist(n, vector<ll>(3, -1));
    dist[s][0] = 0;
    queue<pii> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        pii now = q.front(); q.pop();
        int u = now.first;
        int parity = now.second;
        for (auto v: g[u]) {
            int np = (parity + 1) % 3;
            if (dist[v][np] == -1) {
                dist[v][np] = dist[u][parity] + 1;
                q.emplace(v, np);
            }
        }
    }

    if (dist[t][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[t][0] / 3 << endl;
    }
}
