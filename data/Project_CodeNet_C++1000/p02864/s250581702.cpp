#include <iostream>
using namespace std;
int lol[300] = {};
long long dp[300][300] = {};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (n == k) cout << 0 << '\n';
    else{
        for (int i = 0; i < n; i++) cin >> lol[i];
        for (int r = 0; r < n; r++) dp[0][r] = lol[r];
        for (int s = 1; s < n-k; s++){
            for (int r = s; r < n; r++){
                long long m = 1ll<<56;
                for (int t = s-1; t < r; t++) m = min(m, dp[s-1][t] + max(0, lol[r] - lol[t]));
                dp[s][r] = m;
            }
        }
        long long ans = 1ll<<56;
        for (int r = n-k-1; r < n; r++) ans = min(ans, dp[n-k-1][r]);
        cout << ans << '\n';
    }
}
