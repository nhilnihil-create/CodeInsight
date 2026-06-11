#include<bits/stdc++.h>
using namespace std;

int main(void){
    int h,n;
    cin >> h >> n;
    int a[n],b[n];
    for(int i = 0;i < n;i++)cin >> a[i] >> b[i];
    
    int dp[n+1][h+1];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= h;j++)dp[i][j] = 1e9;
    }
    
    dp[0][0] = 0;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= h;j++){
            dp[i+1][j] = min(dp[i][j],dp[i+1][max(0,j-a[i])]+b[i]);
        }
    }
    
    cout << dp[n][h] << endl;
}