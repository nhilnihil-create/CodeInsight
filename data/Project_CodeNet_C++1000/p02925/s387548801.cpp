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
#define pb push_back

ll id(ll x, ll y) 
{
    if(x > y) swap(x, y);
    return x * 1005 + y;
}

int main()
{
    ll N;
    cin >> N;
    ll M = id(N, N);
    
    mat G(M);
    vec inD(M, -1);
    REP(i,1,N+1) {
        ll a, b;
        cin >> a;
        if(inD[id(i,a)] == -1) inD[id(i,a)] = 0;
        REP(j,0,N-2) {
            cin >> b;
            G[id(i,a)].pb(id(i,b));
            if(inD[id(i,b)] == -1) inD[id(i,b)] = 0;
            ++inD[id(i,b)];
            a = b;
        }
    }

    REP(i,0,M) {
        if(inD[i] == 0) {
            G[id(0,0)].pb(i);
            ++inD[i];
        }
    }

    auto H = G;

    vec S, I;
    ll k = 0;
    S.push_back(id(0, 0));
    while(!S.empty()) {
        ll v = S.back(); S.pop_back();
        I.push_back(v);
        while(!G[v].empty()) {
            ll nv = G[v].back(); G[v].pop_back();
            --inD[nv];
            if(inD[nv] == 0) S.push_back(nv);
        }
    }

    vec D(M, 0);
    ll m = -1;
    bool isDAG = true;
    REP(i,0,M) {
        if(SZ(G[i]) > 0) {
            isDAG = false;
            break;
        }
    }
    if(isDAG) {
        FORR(i,I) {
            FORR(nv,H[i]) D[nv] = MAX(D[nv],D[i]+1);
        }
        FORR(i,I) m = MAX(m,D[i]);
    }
    PR(m);

    return 0;
}

/*



*/