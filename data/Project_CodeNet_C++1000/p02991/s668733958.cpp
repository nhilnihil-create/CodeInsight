#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

const int INF = 1e18;
vvi G(100050);
vvi dis(100050, vi(3, INF));

void dfs(int now, int cost) {
    int t = (cost+1)%3;
    rep(i, G[now].size()) {
        if(dis[G[now][i]][t]>cost+1) {
            dis[G[now][i]][t] = cost+1;
            dfs(G[now][i], cost+1);
        }
    }
}

void dijkstra(int s) {
    priority_queue<P, V(P), greater<P>> q;
    q.push(P(0, s));

    while(!q.empty()) {
        P p = q.top();
        q.pop();
        int t = (p.fi+1)%3;
        rep(i, G[p.se].size()) {
            if(dis[G[p.se][i]][t] > p.fi+1) {
                dis[G[p.se][i]][t] = p.fi+1;
                q.push(P(p.fi+1, G[p.se][i]));
            }
        }
    }

}


signed main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].pb(v);
    }
    int S, T;
    cin >> S >> T;
    S--; T--;
    dis[S][0] = 0;

    //dfs(S, 0);
    dijkstra(S);

    if(dis[T][0]!=INF) cout << dis[T][0]/3 << endl;
    else cout << -1 << endl;

    return 0;
}