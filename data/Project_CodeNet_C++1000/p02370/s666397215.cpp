#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repq(i,a,n) for(int i=a; i<=n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 2000000000
#define int long long int

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// ?§?????????¨????????¨???????????????????¨???????????§???????
struct Edge {
    int from, to, cost;
    Edge(int s, int d) : to(s), cost(d) {}
    Edge(int f, int s, int d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

// 1??????????????????????????????????????±????????????????????????????????? vector
// Edges????????????????????????????????????????????°??????????????????
typedef vector<Edge> Edges;

// ???????????±??????????????? vector
// Graph??????????????????????????°?????????????????§??? V ??§?????????
typedef vector<Edges> Graph;

/*vector<int> tpsort_Kahn(const Graph &g) {
    const int V = g.size();
    vector<int> indeg(V, 0);
    stack<int> S;

    rep(i,0,V) rep(j,0,g[i].size())
        indeg[ g[i][j].to ]++;
    rep(i,0,V) if(indeg[i] == 0) S.push(i);

    vector<int> ans;
    while(S.size() > 0) {
        int u = S.top(); S.pop();
        ans.pb(u);
        rep(i,0,g[u].size()) {
            indeg[ g[u][i].to ]--;
            if(indeg[ g[u][i].to ] ==  0)
                S.push( g[u][i].to );
        }
    }
    return ans;
}*/

void tpTarjanVisit(const Graph &g, int u, vector<bool> &used, vector<int> &ans) {
    if(used[u] == false) {
        used[u] = true;
        rep(i,0,g[u].size()) 
            tpTarjanVisit(g, g[u][i].to, used, ans);
        ans.pb(u);
    }
}

vector<int> tpsort_Tarjan(const Graph &g) {
    const int V = g.size();
    vector<bool> used(V, false);
    vector<int> ans;
    rep(i,0,V) tpTarjanVisit(g, i, used, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main() {
    int V, E; cin >> V >> E;
    Graph G(V);
    int s, t;
    rep(i,0,E) {
        cin >> s >> t;
        G[s].pb(Edge(t,1));
    }
    vector<int> ans = tpsort_Tarjan(G);
    rep(i,0,ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}