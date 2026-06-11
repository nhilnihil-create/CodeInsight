#include <iostream>
#define endl '\n'
using namespace std;
const int num=2e3+1;
int s,dp[num],mod=1e9+7;
int solve(int n){
    int ret=0;
    if(dp[n]!=1)return dp[n];
    for(int i=3;i<=n-3;++i)ret=(ret+solve(i))%mod;
    dp[n]=(ret+dp[n])%mod;
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>s;
    fill(dp,dp+s+1,1);
    for(int i=0;i<3;++i)dp[i]=0;
    cout<<solve(s)%mod<<endl;;
    return 0;
}
