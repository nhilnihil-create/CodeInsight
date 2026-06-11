#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int n, d[100005];
struct edge{int to, cost;};
vector<edge> g[100005];
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n;
    rep(i, 0, n) {
        int u, k;
        cin >> u >> k;
        rep(j, 0, k) {
            int v, c;
            cin >> v >> c;
            edge e;
            e.to = v, e.cost = c;
            g[u].pb(e);
        }
    }

    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, INF);
    d[0] = 0;
    que.push({d[0], 0});
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < g[v].size(); i++) {
            edge e = g[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    rep(i, 0, n) {
        cout << i << " " << d[i] << endl;
    }
    return 0;
}
