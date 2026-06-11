#include<iostream>
#include<string>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int mod = 1000000007;
    string l;
    cin >> l;
    long int dp[l.size()][2];
    // 0:l以下が確定, 1:l以下が未確定
    dp[0][0] = 1;
    dp[0][1] = 2;
    for(int i = 1; i < l.size(); i++){
        if (l[i] == '0') {
            dp[i][0] = dp[i-1][0] * 3;
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0] * 3 + dp[i-1][1];
            dp[i][1] = dp[i-1][1] * 2;
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        // cout << dp[i][0] + dp[i][1] << endl;
    }
    long int ans = dp[l.size()-1][0] + dp[l.size()-1][1];
    ans %= mod;
    cout << ans << endl;
}