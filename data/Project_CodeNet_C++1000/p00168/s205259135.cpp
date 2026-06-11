#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int dp[35];
    rep(i,35) dp[i] = 0;
    dp[0] = 1;
    rep(i,35){
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
        dp[i+3] += dp[i];
    }
    int n;
    while(cin >> n && n) {
        int step = dp[n];
        int ans = step/3650;
        if(step%3650 != 0) ans++;
        cout << ans << endl;
    }
}