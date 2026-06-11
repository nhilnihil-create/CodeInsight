#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[20001];
long long findcount(long long S,long long curr){
    if(S==0) return 1;
    if(curr>S) return 0;
    if(dp[S]!=-1) return dp[S];
    long long op1=findcount(S-curr,3);
    long long op2=findcount(S,curr+1);
    return dp[S]=(op1+op2)%1000000007;
}
int main()
{
    long long int n,ans=0;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    ans=findcount(n,3);
    printf("%lld\n",ans);
    return 0;
}