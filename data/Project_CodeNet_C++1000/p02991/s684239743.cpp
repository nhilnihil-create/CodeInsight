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
int d[100005];
vector<int> g[100005];

void bfs(int s) {
    queue<int> q1, q2, q3;
    rep(i, 0, n) d[i] = -1;

    q1.push(s);
    d[s] = 0;
    while (!q1.empty()) {
        int u = q1.front(); q1.pop();
        for (int v1 : g[u]) {
            q2.push(v1);
        }

        while (!q2.empty()) {
            int v1 = q2.front(); q2.pop();
            for (int v2 : g[v1]) {
                q3.push(v2);
            }
        }

        while (!q3.empty()) {
            int v2 = q3.front(); q3.pop();
            for (int v3 : g[v2]) {
                if (d[v3]==-1) {
                    d[v3] = d[u] + 1;
                    if (v3==t) return;
                    q1.push(v3);
                }
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
        g[u].pb(v);
    }
    cin >> s >> t;
    s--; t--;

    bfs(s);

    cout << d[t] << "\n";
    return 0;
}

