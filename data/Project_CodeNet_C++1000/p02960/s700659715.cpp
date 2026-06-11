#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll mod = 1000000007;
int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(13, 0));
    dp[0][0] = 1;
    ll x = 1;
    rep(i, n){
        if(s[i] == '?'){
            rep(j, 10){
                int memo = x * j;
                memo %= 13;
                rep(k, 13){
                    dp[i + 1][(k + memo)%13] += dp[i][k];
                    dp[i+1][(k+memo)%13] %= mod;
                }
            }
        }else{
            int s0 = s[i] - '0';
            s0 = s0 * x;
            s0 %= 13;
            rep(k, 13){
                dp[i + 1][(k + s0)%13] += dp[i][k];
                dp[i+1][(k+s0)%13] %= mod;
            }
        }
        x *= 10;
        x %= 13;
    }
    cout << dp[n][5] << endl;
    return 0;
}