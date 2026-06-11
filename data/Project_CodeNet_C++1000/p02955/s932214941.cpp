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

vec divisor(ll N)
{
    vec D;
    int i;
    
    D.pb(N);
    for(i=2; i*i<N; ++i) {
        if(N % i == 0) {
            D.pb(i);
            D.pb(N/i);
        }
    }
    if(N % (i*i) == 0) D.pb(i*i);
    DESC(D);

    return D;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    ll sum = 0;
    REP(i,0,N) sum += A[i];
    vec D = divisor(sum);
    vec B(N), lsum(N+2), rsum(N+2);

    ll k, m = 1;
    FORR(d,D) {
        REP(i,0,N) B[i] = A[i] % d;
        ASC(B);
        REP(i,0,N+2) {
            lsum[i] = 0;
            rsum[i] = 0;
        }
        REP(i,1,N+1) {
            lsum[i] = B[i-1] + lsum[i-1];
            rsum[N-i+1] = d - B[N-i] + rsum[N-i+2];
        }
        k = INF;
        REP(i,1,N) {
            if(lsum[i] == rsum[i+1]) {
                k = lsum[i];
                break;
            }
        }
        if(k <= K) m = MAX(m,d);
    }

    PR(m);


    return 0;
}

/*



*/