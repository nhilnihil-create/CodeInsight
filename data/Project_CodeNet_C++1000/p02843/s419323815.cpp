#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x,i;
    int dp[100010] = {};
    cin >> x;

    dp[0] = 1;

    for(i=100; i<=105; i++){
        dp[i] = 1;
    }

    for(i=106; i<=x; i++){
        dp[i] = max(dp[i-100],max(dp[i-101],max(dp[i-102],max(dp[i-103],max(dp[i-104],dp[i-105])))));
    }
    cout << dp[x] << endl;

    return 0;
}