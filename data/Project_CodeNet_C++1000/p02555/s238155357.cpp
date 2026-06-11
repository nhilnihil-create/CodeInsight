#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll s = 0;
    cin >> s;
    if(s < 3){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(s+1, 0);
    dp[3] = 1;
    for(int i = 4; i <= s; i++) 
        dp[i] = (dp[i-1] + dp[i-3]) % 1000000007;
    cout << dp[s] << endl;
    return 0;
}
