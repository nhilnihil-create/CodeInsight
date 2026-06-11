#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MAXN = 5e3+5;
const long long MOD = 998244353;
long long dp[MAXN][MAXN];
long long arr[MAXN];
int main(){
    long long n,S;
    cin>>n>>S;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[0][0] = 1;
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<=S;j++){
            dp[i][j] = 2LL*dp[i-1][j];
            dp[i][j]%=MOD;
            if(j-arr[i]>=0){
                dp[i][j]+=dp[i-1][j-arr[i]];
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[n][S]<<endl;
}