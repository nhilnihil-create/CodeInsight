#include<bits/stdc++.h>

#define ntest 0

using namespace std;
const int mod = 1e9 + 7;
int s;
int dp[2005];
void solve() {
    cin >> s;
    dp[0] = 1;
    for (int i = 3; i <= s; ++i) {
        for (int j = 3; j <= i; ++j) dp[i] = (dp[i] + dp[i-j]) % mod;
    }
    cout << dp[s];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


