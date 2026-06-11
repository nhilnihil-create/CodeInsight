#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const long long MOD = 1000000007;

ll N, M;
ll S[100010], T[100010];
ll dp[2010][2010];
ll mp[100010];

ll solve(){
    dp[0][0] = 1;
    REP(i, N) dp[i + 1][0] = 1;
    REP(j, M) dp[0][j + 1] = 1;
    REP(i, N){
        REP(j, 100010) mp[j] = 0;
        REP(j, M){
            mp[T[j]] = (mp[T[j]] + dp[i][j]) % MOD;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j + 1] + mp[S[i]]) % MOD;
        }
    }
    return dp[N][M];
}

signed main(){
    cin >> N >> M;
    REP(i, N) cin >> S[i];
    REP(i, M) cin >> T[i];
    PRINT(solve());
    return 0;
}