#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

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
    vec X(N, 0);
    REP(i,0,Q) {
        ll p, x;
        cin >> p >> x;
        X[p-1] += x;
    }

    queue<ll> R;
    vec A(N, 0);
    vector<bool> F(N, false);
    R.push(0);
    A[0] += X[0];
    F[0] = true;
    while(!R.empty()) {
        ll v = R.front(); R.pop();
        FORR(nv,G[v]) {
            if(!F[nv]) {
                A[nv] += A[v] + X[nv];
                R.push(nv);
                F[nv] = true;
            }
        }
    }

    REP(i,0,N) PS(A[i]);
    PR("");

    return 0;
}

/*



*/