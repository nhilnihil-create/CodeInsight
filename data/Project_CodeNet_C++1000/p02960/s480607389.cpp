#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    string s; cin >> s;
    int n = s.size();
    ll dp[n+1][13]; rep(i,n+1) rep(j,13) dp[i][j] = 0;
    dp[0][0] = 1;
    int d = -1;
    rep(i,n) {
        d = s[i]-'0';
        if (d == 15) {
            rep(d,10) {
                rep(j,13) {
                    dp[i+1][(10*j+d)%13] += dp[i][j];
                }
            }
            rep(j,13) dp[i+1][j] %= mod;
        } else {
            rep(j,13) {
                dp[i+1][(10*j+d)%13] = (dp[i][j]+dp[i+1][(10*j+d)%13])%mod;
            }

        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
