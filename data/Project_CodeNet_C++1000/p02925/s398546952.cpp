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

using Graph = vector<vector<int>>;
const int MAXN = 1005;
const int MAXV = 1000005;

int n;
int id[MAXN][MAXN];
int dist[MAXV];
int state[MAXV]; // 0:未訪問 1:探索中 2:探索済み

int toId(int i, int j) {
    if (i > j) swap(i, j);
    return id[i][j];
}

int dfs(const Graph &g, int u) {
    if (state[u] == 1) return -1; // サイクル検出
    if (state[u] == 2) return dist[u]; // 探索済みなので何もしない

    state[u] = 1;
    dist[u] = 1;
    for (int v: g[u]) {
        int res = dfs(g, v);
        if (res == -1) return -1;
        dist[u] = max(dist[u], res + 1);
    }
    state[u] = 2;
    return dist[u];
}

int main() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    int m = n * (n-1) / 2;
    Graph g(m);

    rep(i, n) {
        rep(j, n-1) { 
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int V = 0;
    rep(i, n) rep(j, n) {
        if (i < j) id[i][j] = V++;
    }

    rep(i, n) {
        rep(j, n-1) {
            a[i][j] = toId(i, a[i][j]);
        }
        rep(j, n-2) {
            g[a[i][j+1]].push_back(a[i][j]);
        }
    }

    int ans = 0;
    rep(i, V) {
        int res = dfs(g, i);
        if (res == -1) {
            cout << -1 << endl;
            return 0;
        }
        chmax(ans, res);
    }
    cout << ans << endl;
}
