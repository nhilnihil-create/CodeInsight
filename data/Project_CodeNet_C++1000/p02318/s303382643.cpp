#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s,t;cin >> s >> t;
    int a = s.size(),b = t.size(),i,j,dp[a+1][b+1] = {};
    for(i=1;i<=a;i++) dp[i][0] = i;
    for(i=1;i<=b;i++) dp[0][i] = i;
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    cout << dp[a][b] << endl;
}
