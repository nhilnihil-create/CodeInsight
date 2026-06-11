#include <bits/stdc++.h>
using namespace std;

int main(){
    string price;
    cin >> price;

    price = '0' + price;
    reverse(price.begin(),price.end());
    int n= price.length();

    vector<vector<int>> dp(n+1,vector<int>(2, 1e9));// dp[i][j] = i-th digit, j=0/1 : carry NO/YES
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        int x = price[i] - '0';
        
        dp[i+1][0] = min(dp[i][0] + x,      dp[i][1] + (x+1));
        dp[i+1][1] = min(dp[i][0] + (10-x), dp[i][1] + (10-(x+1)));
    }
    cout << dp[n][0] << endl;
    return 0;
}