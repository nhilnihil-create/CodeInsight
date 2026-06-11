#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int s;
    cin >> s;
    vector<int> dp(s+1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i <= s; i++) {
        dp[i] = dp[i -3] + dp[i - 1];
        dp[i] %= mod;
    }
    cout << dp[s] << endl;
}