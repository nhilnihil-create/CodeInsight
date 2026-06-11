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

ll ceilll(ll a, ll b) {
    return (a + b - 1) / b;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vec A(N), F(N);
    REP(i,0,N) cin >> A[i];
    REP(i,0,N) cin >> F[i];

    ASC(A); DESC(F);

    ll ng = -1, ok = INF;
    while(abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        ll sum = 0;
        REP(i,0,N) {
            sum += MAX(ceilll(A[i]*F[i]-mid,F[i]),0);
        }
        if(sum <= K) ok = mid;
        else ng = mid;
    }

    PR(ok);

    return 0;
}

/*



*/