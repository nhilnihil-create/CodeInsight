#include <bits/stdc++.h>
using namespace std;
using f32 = float;
using f64 = double;
using LL = long long;
using ULL = unsigned long long;
#define REP(i, n) for (LL i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define all(x) (x).begin(), (x).end()
const long long MOD = 998244353;
int main(){
    long long N,S;
    scanf("%lld",&N);
    scanf("%lld",&S);
    vector<long long> A(N);
    REP(i,N)scanf("%lld",&A[i]);
    vector<vector<long long>> dp(N+1, vector<long long>(S+1, 0));
    dp[0][0] = 1;
    REP(i,N){
        REP(j,S+1){
          dp[i + 1][j] += 2 * dp[i][j];
             dp[i + 1][j] %= MOD;
           if (j + A[i] <= S) dp[i + 1][j + A[i]] += dp[i][j];
           dp[i + 1][j + A[i]] %= MOD;
        }
    }
    printf("%lld",dp[N][S]);
    return 0;
}