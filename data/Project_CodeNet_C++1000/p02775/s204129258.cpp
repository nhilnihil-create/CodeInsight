#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(n+10, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i, 0, n) {
        ll cur = s[i] - '0';
        dp[i+1][0] = min(dp[i][0] + cur, dp[i][1] + (10 - cur));
        dp[i+1][1] = min(dp[i][0] + cur + 1, dp[i][1] + (9 - cur));
    }
    cout << dp[n][0] << endl;
    return 0;
}