#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[5005][5005];

int main(void){
    int n;
    string s;
    cin >> n >> s;

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]==s[j]) dp[i][j] = min(dp[i+1][j+1]+1,abs(i-j));
        }
    }


    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    */

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}