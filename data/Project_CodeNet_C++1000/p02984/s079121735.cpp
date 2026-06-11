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
    vec A(N+1);
    REP(i,1,N+1) cin >> A[i];

    vec CO((N+1)/2+1, 0), CE((N-1)/2+1, 0);
    REP(i,1,(N+1)/2+1) CO[i] += CO[i-1] + A[i*2-1] * 2;
    REP(i,1,(N-1)/2+1) CE[i] += CE[i-1] + A[i*2] * 2;

    vec B(N+1);
    ll S = (CO[(N+1)/2] + CE[(N-1)/2]) / 2;
    REP(i,1,(N+1)/2+1) B[i*2-1] = S - (CO[i-1] + CE[(N-1)/2] - CE[i-1]);
    REP(i,1,(N-1)/2+1) B[i*2] = S - (CE[i-1] + CO[(N+1)/2] - CO[i]);
    REP(i,1,N+1) PS(B[i]);
    PR("");

    return 0;
}

/*



*/