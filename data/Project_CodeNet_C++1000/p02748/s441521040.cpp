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
    ll A, B, M;
    cin >> A >> B >> M;
    vec a(A), b(B), x(M), y(M), c(M);
    REP(i,0,A) cin >> a[i];
    REP(i,0,B) cin >> b[i];
    REP(i,0,M) cin >> x[i] >> y[i] >> c[i];

    ll mn = INF;
    REP(i,0,M) mn = MIN(mn,a[x[i]-1]+b[y[i]-1]-c[i]);
    ASC(a);
    ASC(b);
    PR(MIN(mn,a[0]+b[0]));

    return 0;
}

/*



*/