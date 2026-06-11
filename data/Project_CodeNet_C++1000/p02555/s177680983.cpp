#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll s = 0;
    cin >> s;
    vector<ll> dp(2001, 0);
    dp[3] = 1;
    for(int i = 4; i <= s; i++) 
        dp[i] = (dp[i-1] + dp[i-3]) % 1000000007;
    cout << dp[s] << endl;
    return 0;
}
