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

void bfs(mat G, ll r, vector<bool>& f, vec& y)
{
    queue<ll> Q;
    Q.push(r);
    f[r] = true;
    while(!Q.empty()) {
        ll v = Q.front(); Q.pop();    
        FORR(nv,G[v]) {
            if(!f[nv]) {
                Q.push(nv);
                y[nv] += y[v];
                f[nv] = true;
            }
        }
    }
}


int main()
{
    ll N, Q;
    cin >> N >> Q;
    mat G(N);
    REP(i,0,N-1) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    vec y(N, 0);
    REP(i,0,Q) {
        ll p, x;
        cin >> p >> x;
        --p;
        y[p] += x;
    }
    
    vector<bool> f(N, false);
    bfs(G, 0, f, y);
    REP(i,0,N) PS(y[i]);
    PR("");

    return 0;
}

/*



*/