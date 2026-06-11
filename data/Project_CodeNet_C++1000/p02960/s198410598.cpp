#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    string s;   cin >> s;
    ll l = s.length(), mod = 1e9+7;
    vector<vector<ll> > dp(l+1, vector<ll>(13));
    
    dp[0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 13; j++) {
            if (s[i] == '?') {
                for (int k = 0; k < 10; k++) {
                    dp[i+1][(10*j+k)%13] = (dp[i+1][(10*j+k)%13] + dp[i][j]) % mod;
                }
            }
            else {
                int k = s[i]-'0';
                dp[i+1][(10*j+k)%13] = (dp[i+1][(10*j+k)%13] + dp[i][j]) % mod;
            }
        }
    }

    cout << dp[l][5] << endl;
}