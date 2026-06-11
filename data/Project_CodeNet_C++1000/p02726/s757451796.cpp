#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define pb push_back


void bfs(mat G, ll s, vec& C)
{
    ll N = SZ(G);
    vector<ll> D(N, -1);
    queue<ll> Q;
    D[s] = 0;
    Q.push(s);
    
    while(!Q.empty()) {
        ll v = Q.front(); Q.pop();
        FORR(nv,G[v]) {
            if(D[nv] == -1) {
                D[nv] = D[v] + 1;
                Q.push(nv);
            }
        }
    }

    REP(i,0,N) ++C[D[i]];

}


int main()
{
    ll N, X, Y;
    cin >> N >> X >> Y;
    mat G(N);
    REP(i,0,N-1) {
        G[i].pb(i+1);
        G[i+1].pb(i);
    }
    --X; --Y;
    G[X].pb(Y);
    G[Y].pb(X);

    vec D(N, 0);
    REP(i,0,N) {
        vec C(N, 0);
        bfs(G, i, C);
        REP(j,0,N) D[j] += C[j];
    }

    REP(i,1,N) PR(D[i]/2);   

    return 0;
}

/*



*/