// 解説
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int ans, n, m, s, t;
int d[100005*3];
vector<int> g[100005*3];

void bfs(int s) {
    queue<int> q;
    rep(i, 0, 100005*3) d[i] = -1;

    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
          if (d[v]==-1) {
            d[v] = d[u]+1;
            q.push(v);
          }
        }
     }
}

int main(void) {

    cin >> n >> m;

    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u*3].pb(v*3+1);
        g[u*3+1].pb(v*3+2);
        g[u*3+2].pb(v*3);
    }
    cin >> s >> t;
    s--; t--;

    bfs(s*3);
    
    
    cout << (d[t*3]==-1 ? -1 : d[t*3]/3) << "\n";
    return 0;
}

