#include<bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin >> N;
    int n = N.length();
    long long int S[n+1];
    int i;
    for(i=0;i<n;i++)S[i+1]=N[i]-'0';
    S[0]=0;
    long long int dp[n+1][2];
    dp[0][0]=0;dp[0][1]=1;
    for(i=1;i<n+1;i++){
        dp[i][0]=min(dp[i-1][0]+S[i],dp[i-1][1]+10-S[i]);
        dp[i][1]=min(dp[i-1][0]+1+S[i],dp[i-1][1]+10-S[i]-1);
    }
    cout << dp[n][0] << endl;
}