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
#define REV(x) reverse(ALL((x)))
#define eb emplace_back

int main()
{
    ll N, M;
    cin >> N >> M;
    mat G(N*3);
    REP(i,0,M) {
        ll v, w;
        cin >> v >> w;
        --v; --w;
        G[v*3].eb(w*3+1);
        G[v*3+1].eb(w*3+2);
        G[v*3+2].eb(w*3);
    }
    ll S, T;
    cin >> S >> T;
    S = (S-1)*3; T = (T-1)*3;

    vec D(N*3, -1);
    queue<ll> Q;

    D[S] = 0;
    Q.push(S);
    while(!Q.empty() && D[T] == -1) {
        ll v = Q.front(); Q.pop();
        FORR(nv,G[v]) {
            if(D[nv] == -1) {
                D[nv] = D[v] + 1;
                Q.push(nv);
            }
        }
    }
    PR(D[T]==-1?-1:D[T]/3);


    
    return 0;
}

/*



*/