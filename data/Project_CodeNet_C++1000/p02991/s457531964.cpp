#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INF (1LL << 60)
#define MOD 1000000009

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((int)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back


int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N*3);
    ll u, v;
    REP(i,0,M) {
        cin >> u >> v;
        --u; --v;
        G[u*3].pb(v*3+1);
        G[u*3+1].pb(v*3+2);
        G[u*3+2].pb(v*3);
    }
    ll S, T;
    cin >> S >> T;
    S = (S - 1) * 3;
    T = (T - 1) * 3;

    queue<ll> Q;
    vector<ll> dist(N*3, -1);
    Q.push(S);
    dist[S] = 0;

    while(!Q.empty()) {
        v = Q.front();
        Q.pop();
        FORR(nv,G[v]) {
            if(dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                Q.push(nv);
            }
        }
    }
    
    ll ans = dist[T];
    if(ans == -1) _PR(-1);
    else _PR(ans/3);

    return 0;
}

/*



*/