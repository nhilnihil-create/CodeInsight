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

int main()
{
    ll N;
    cin >> N;
    vec A(N+1, 0);
    REP(i,1,N+1) cin >> A[i];

    vec B(N+1, 0), C((N+1)/2+1, 0), D((N-1)/2+1, 0);
    ll S = 0;
    for(ll i=1; i<=N; ++i) S += A[i];
    S /= 2;
    for(ll i=1; i<=(N+1)/2; ++i) C[i] = C[i-1] + A[2*i-1];
    for(ll i=1; i<=(N-1)/2; ++i) D[i] = D[i-1] + A[2*i];

    for(ll i=1; i<=(N+1)/2; ++i) B[2*i-1] = S - C[i-1] - D[(N-1)/2] + D[i-1];
    for(ll i=1; i<=(N-1)/2; ++i) B[2*i] = S - D[i-1] - C[(N+1)/2] + C[i];

    for(ll i=1; i<=N; ++i) PR(B[i]*2);

    return 0;
}

/*



*/