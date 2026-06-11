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
    vec S(N+1, 0), T(M+1, 0);
    REP(i,1,N+1) cin >> S[i];
    REP(i,1,M+1) cin >> T[i];

    mat dp(N+1, vec(M+1, 0));
    REP(i,0,N+1) dp[i][0] = 1;
    REP(i,0,M+1) dp[0][i] = 1;

    REP(i,1,N+1) {
        REP(j,1,M+1) {
            if(S[i] == T[j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + MOD) % MOD;
        }
    }
    PR(dp[N][M]);

    return 0;
}

/*



*/