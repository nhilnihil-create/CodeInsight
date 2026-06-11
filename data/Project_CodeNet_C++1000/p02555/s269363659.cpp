#include<bits/stdc++.h>
using namespace std;

long calc(long n,vector<long>&dp,long mod){
    if(n<3)return 0;
    if(dp[n]!=0)return dp[n];
    for(int i=3;i<=n;i++){
        
        if(n!=i)dp[n] += calc(n-i,dp,mod);
        else dp[n]++;
        dp[n] %= mod;
    }
    dp[n]%=mod;


    return dp[n];
}

int main(){
    long s;
    cin >> s;
    long const mod = 1e9+7;
    vector<long>dp(s+1);
    if(s>=3)dp[3] = 1;

    cout << calc(s,dp,mod)<<endl;
    
}