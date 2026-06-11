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
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = 2;
    dp[0][1] = 1;
    ll mod = 1000000007;
    for(int i = 1; i < n; i++){
        if(s[i] == '0'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] * 3 % mod;
        }else{
            dp[i][0] = dp[i-1][0] * 2 % mod;
            dp[i][1] = dp[i-1][0] + dp[i-1][1] * 3 % mod;
            dp[i][1] %= mod;
        }
    }
    cout << (dp[n-1][0] + dp[n-1][1]) % mod << endl;
}