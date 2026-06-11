#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll MOD = 1000000007;
    int N, M;
    cin >> N >> M;
    vector<ll> s(N);
    vector<ll> t(M);
    
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < M; i++)
        cin >> t[i];
    
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    vector<vector<ll>> sum_dp(N+1, vector<ll>(M+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = (sum_dp[i-1][j-1]+1) % MOD;
                sum_dp[i][j] = ((sum_dp[i][j-1]-sum_dp[i-1][j-1]+sum_dp[i-1][j])%MOD+dp[i][j])%MOD;
                //ll d_sum = 0;
                //for (int k = 0; k < i; k++)
                //    for (int l = 0; l < j; l++)
                //        d_sum = (d_sum + dp[k][l]) % MOD;
                //dp[i][j] = (d_sum + 1) % MOD;
            }
            else {
                dp[i][j] = 0;
                sum_dp[i][j] = (sum_dp[i][j-1]-sum_dp[i-1][j-1]+sum_dp[i-1][j])%MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            ans = (ans + dp[i][j]) % MOD;
    if ((ans+1)%MOD >= 0)
        cout << (ans+1)%MOD << endl;
    else
        cout << (ans+1)%MOD + MOD << endl;
}