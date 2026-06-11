#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;

int main() {
    FASTIO

    int s;
    cin >> s;
    if(s < 3) cout << "0\n";
    else if(s < 6 && s >= 3) cout << "1\n";
    else {
        vector<ll> dp(s+1,1);
        dp[0] = dp[1] = dp[2] = 0;
        for(int i=6; i<=s; i++) {
            for(int j=3; j<=i-3; j++) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
        cout << dp[s]%MOD << "\n";
    }
    
    return 0;
}