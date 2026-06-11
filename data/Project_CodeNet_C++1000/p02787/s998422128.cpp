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

#define M 10000

int main()
{
    ll H, N;
    cin >> H >> N;
    vec A(N), B(N);
    REP(i,0,N) cin >> A[i] >> B[i];

    mat dp(N+1, vec(H+1, INF));
    dp[0][0] = 0;
    REP(i,0,N) {
        REP(j,0,H+1) {
            dp[i+1][j] = MIN(dp[i+1][j],dp[i][j]);
            dp[i+1][MIN(j+A[i],H)] = MIN(dp[i+1][MIN(j+A[i],H)],dp[i+1][j]+B[i]);
        }
    }

    PR(dp[N][H]);

    return 0;
}

/*



*/