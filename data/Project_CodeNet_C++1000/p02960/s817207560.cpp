#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MOD = 1000000007;

string S;
int dp[100100][15];

int mod_pow(int x, int n, int mod) {
    int res = 1;
    while (n>0) {
        if (n&1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    reverse(S.begin(), S.end());
    dp[0][0] = 1;
    rep(i, S.size()) {
        int p = mod_pow(10, i, 13);
        if (S[i]=='?') {
            rep(j, 10) rep(k, 13) {
                dp[i+1][(j*p+k)%13] += dp[i][k];
                dp[i+1][(j*p+k)%13] %= MOD;
            }
        }
        else {
            int d = S[i]-'0';
            rep(j, 13) {
                dp[i+1][(d*p+j)%13] += dp[i][j];
                dp[i+1][(d*p+j)%13] %= MOD;
            }
        }
    }
    cout << dp[S.size()][5] << endl;
}