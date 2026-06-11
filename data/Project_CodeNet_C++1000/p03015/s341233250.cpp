#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int const mod = 1000000007;
    string l;
    cin >> l;
    long int n = l.size();
    long int dp[n][2];
    dp[0][0] = 2;
    dp[0][1] = 1;
    rep(i, n - 1){
        if (l[i+1] == '1'){
            dp[i+1][0] = dp[i][0] * 2;
            dp[i+1][0] %= mod;
            dp[i+1][1] = dp[i][0] * 1 + dp[i][1] * 3;
            dp[i+1][1] %= mod;
        }else{
            dp[i+1][0] = dp[i][0];
            dp[i+1][0] %= mod;
            dp[i+1][1] = dp[i][1] * 3;
            dp[i+1][1] %= mod;
        }
    }
    long int ans = dp[n-1][0] + dp[n-1][1];
    ans %= mod;
    cout << ans << endl;
}
