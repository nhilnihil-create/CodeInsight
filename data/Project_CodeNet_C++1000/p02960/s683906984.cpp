#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(13,0));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 13; j++){
            if(s[i] == '?'){
                for(int k = 0; k < 10; k++){
                    dp[i+1][(j*10+k)%13] += dp[i][j];
                    dp[i+1][(j*10+k)%13] %= mod;
                }
            }
            else {
                dp[i+1][(j*10+s[i]-'0')%13] = dp[i][j];
                dp[i+1][(j*10+s[i]-'0')%13] %= mod;
            }
        }
    }
    cout << dp[n][5] << endl;
}