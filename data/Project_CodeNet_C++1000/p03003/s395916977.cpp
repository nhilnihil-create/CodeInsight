#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((int)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N+1, 0), T(M+1, 0);
    REP(i,1,N+1) cin >> S[i];
    REP(j,1,M+1) cin >> T[j];

    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));

    dp[0][0] = 1;
    REP(i,1,N+1) dp[i][0] = 1;
    REP(j,1,M+1) dp[0][j] = 1;
    REP(i,1,N+1) {
        REP(j,1,M+1) {
            if(S[i] == T[j]) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
            dp[i][j] = dp[i][j] - dp[i-1][j-1] >= 0 ? (dp[i][j] - dp[i-1][j-1]) % MOD : (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
        }
    }
    _PR(dp[N][M] % MOD);

    return 0;
}

/*



*/