#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(13, 0LL));
    if(s[0] == '?'){
        rep(i, 10)dp[0][i] = 1;
    }else dp[0][s[0]-'0'] = 1;

    ll mod = 1000000007;
    for(int i = 1; i < n; i++){
        if(s[i] == '?'){
            rep(j, 13)rep(k, 10){
                int m = (j * 10 + k) % 13;
                dp[i][m] += dp[i-1][j];
                dp[i][m] %= mod;
            }
        }else{
            int k = s[i] - '0';
            rep(j, 13){
                int m = (j * 10 + k) % 13;
                dp[i][m] += dp[i-1][j];
                dp[i][m] %= mod;
            }
        }
    }
    cout << dp[n-1][5] << endl;
}