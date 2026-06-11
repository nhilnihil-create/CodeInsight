#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1000000007;
int main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    vector<vector<ll>> dp(s.size()+1,vector<ll>(13));
    dp[0][0] = 1;
    int x = 1;
    rep(i,s.size()){
        if(s[i]!='?'){
            int num = s[i]-'0';
            rep(j,13){
                int p = (j+num*x)%13;
                dp[i+1][p] += dp[i][j];
                dp[i+1][p] %= mod;
            }
        }else{
            rep(num,10){
                rep(j,13){
                    int p = (j+num*x)%13;
                    dp[i+1][p] += dp[i][j];
                    dp[i+1][p] %= mod;
                }
            }
        }
        x *= 10;
        x %= 13;
    }
    cout << dp[s.size()][5] << endl;
    return 0;
}