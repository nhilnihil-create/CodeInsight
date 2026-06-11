#include <iostream>
using namespace std;
int solve(void){
    int X;
    cin >> X;
    int dp[100001];
    dp[0] = 1;
    for(int i=1;i<=99;i++){
        dp[i] = 0;
    }
    for(int i=100;i<=105;i++){
        dp[i] = 1;
    }
    for(int i=106;i<=X;i++){
        if(dp[i-100] || dp[i-101] || dp[i-102] || dp[i-103] || dp[i-104] || dp[i-105]){
            dp[i] = 1;
        }
    }
    return dp[X];
    
}
int main(void){
    
    int ans = solve();
    cout << ans << endl;
}
