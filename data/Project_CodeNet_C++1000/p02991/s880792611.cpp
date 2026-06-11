/* 拡張BFS */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main(){
    int n, m;
    cin >> n >> m;

    vector<ll> g[n];
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    /* 頂点に状態を持たせる（0: ぴったり, 1: 1歩あまり, 2: 2歩あまり） */
    ll dist[n][3];  /* dist[i][j]: iにjの状態で着くまでの最短経路 */
    REP(i, n) REP(j, 3) {
        dist[i][j] = -1;
    }

    /* bfs */
    dist[s][0] = 0;
    queue<P> que;
    que.push({s, 0});

    while(!que.empty()) {
        P tmp = que.front();
        que.pop();

        for(auto next_place: g[tmp.first]) {
            int next_stat = (tmp.second + 1) % 3;
            if(dist[next_place][next_stat] == -1) {
                dist[next_place][next_stat] = dist[tmp.first][tmp.second] + 1;
                que.push({next_place, next_stat});
            }
        }
    }

    if(dist[t][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[t][0] / 3 << endl;
    }

    return 0;
}