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

int main()
{
    ll N, M;
    cin >> N >> M;
    vec A(M+1), C(M+1, 0);
    REP(i,1,M+1) {
        ll b;
        cin >> A[i] >> b;
        REP(j,1,b+1) {
            ll c;
            cin >> c;
            C[i] += 1 << (c - 1);
        }
    }

    mat dp(M+1, vec(1<<N, INF));
    dp[0][0] = 0;
    REP(i,1,M+1) {
        REP(j,0,1<<N) {
            dp[i][j] = MIN(dp[i][j],dp[i-1][j]);
            dp[i][j|C[i]] = MIN(dp[i][j|C[i]],dp[i-1][j]+A[i]);
            dp[i][j|C[i]] = MIN(dp[i][j|C[i]],dp[i-1][j|C[i]]);
        }
    }

    ll ans = dp[M][(1<<N)-1] < INF ? dp[M][(1<<N)-1] : -1;
    PR(ans);

    return 0;
}

/*



*/