#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i_len=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

mat P;
vec buf(10);

void dperm(ll k, ll n, ll p, vec A)
{
    if(k == n) {
        vec p;
        REP(i,0,n) p.pb(buf[i]);
        P.pb(p);
    }
    else {
        REP(i,0,SZ(A)) {
            if(p <= A[i]) {
                buf[k] = A[i];
                p = A[i];
                dperm(k+1, n, p, A);
            }
        }
    }
}

int main()
{
    ll N, M, Q;
    cin >> N >> M >> Q;
    vec a(Q), b(Q), c(Q), d(Q);
    REP(i,0,Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }

    vec A(M);
    REP(i,0,M) A[i] = i + 1;

    dperm(0, N, A[0], A);

    ll sum, m = 0;
    FORR(A,P) {
        sum = 0;
        REP(i,0,Q) {
            if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        m = MAX(m,sum); 
    }
    PR(m);

    return 0;
}

/*



*/