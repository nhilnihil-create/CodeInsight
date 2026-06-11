#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string L;    cin >> L;
    int l = L.length();
    long long mod = 1e9+7;

    vector<vector<long long> > dp(l+1, vector<long long>(2, 0));
    dp[0][0] = 1;

    for (int i = 0; i < l; i++) {
        if (L[i] == '0') {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = 3*dp[i][1]%mod;
        }
        else {
            dp[i+1][0] = 2*dp[i][0] % mod;
            dp[i+1][1] = (3*dp[i][1] % mod + dp[i][0]) % mod;
        }
    }

    /*
    for (int i = 0; i <= l; i++) {
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    */

    cout << (dp[l][1] + dp[l][0]) % mod << endl;

    return 0;
}