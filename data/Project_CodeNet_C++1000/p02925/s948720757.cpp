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

int ans;
int indeg[1000005]; //入次数
int d[1000005];
vector<int> g[1000005];
map<P, int> m;
int num = 1;
int days = 0;

bool topological_sort(int _n, vector<int>& topo) {
    queue<int> q;

    for (int i=1; i<=_n; i++) {
        if (indeg[i]==0) {
            q.push(i);
            d[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v]==0) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return (int)topo.size() == _n;
}



int main(void) {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int s, u, v;
        cin >> s;
        P p = mp(i, s);
        if (s<i) swap(p.first, p.second);
        if (m.count(p)==0) m[p] = num++;
        u = m[p];

        for (int j=2; j<=n-1; j++) {
            int t;
            cin >> t;
            P q = mp(i, t);

            if (t<i) swap(q.first, q.second);
            if (m.count(q)==0) m[q] = num++;
            v = m[q];
            g[u].push_back(v);
            indeg[v]++;
            u = v;
        }

    }

    vector<int> v;
    bool dag = topological_sort(num-1, v);

    if (dag) {
        rep(i, 1, num) {
            ans = max(ans, d[i]);
        }
    } else {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}

