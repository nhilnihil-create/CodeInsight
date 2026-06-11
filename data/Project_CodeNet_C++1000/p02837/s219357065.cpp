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
    ll N;
    cin >> N;
    vec A(N);
    mat X(N), Y(N);
    REP(i,0,N) {
        cin >> A[i];
        REP(j,0,A[i]) {
            ll x, y;
            cin >> x >> y;
            X[i].pb(x-1); Y[i].pb(y);
        }
    }

    ll m = 0;
    vec F(N);
    REP(b,0,1<<N) {
        REP(i,0,N) F[i] = ((b >> i) & 1);
        ll c = 0;
        bool f = true;
        REP(i,0,N) {
            if(F[i]) {
                REP(j,0,A[i]) {
                    if(F[X[i][j]] != Y[i][j]) f = false;
                }
            }
        }
        if(f) {
            REP(i,0,N) c += F[i];
        }
        m = MAX(m,c);
    }

    PR(m);

    return 0;
}

/*



*/