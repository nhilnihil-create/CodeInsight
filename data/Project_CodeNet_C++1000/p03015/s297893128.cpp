#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    string l;
    cin>>l;
    int n=l.size();
    long long dp[n][2]={};
    dp[0][0]=1;
    dp[0][1]=2;
    for(int i=1;i<n;i++){
        dp[i][0]+=dp[i-1][0]*3%mod;
        if(l[i]=='0')dp[i][1]+=dp[i-1][1]%mod;
        else{
            dp[i][0]+=dp[i-1][1]%mod;
            dp[i][1]+=dp[i-1][1]*2%mod;
        }
    }
    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    return 0;
}