#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string L;
    cin>>L;
    int n = L.size();
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = 2;
    dp[0][1] = 1;
    rep(i, n - 1) {
        if (L[i + 1] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (3 * dp[i][1]) % mod;
        }
        else {
            dp[i + 1][0] = (2 * dp[i][0]) % mod;
            dp[i + 1][1] = (dp[i][0] + 3 * dp[i][1]) % mod;
        }
    }
    cout<<(dp[n - 1][0] + dp[n - 1][1]) % mod<<endl;
}