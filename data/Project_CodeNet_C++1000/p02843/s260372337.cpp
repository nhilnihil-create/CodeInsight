#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(void)
{
    int x; cin>>x;
    bool dp[110000];
    dp[0]=true;
    rep(i,x)rep(j,6) if(dp[i]==true) dp[i+100+j]=true;
    cout<<dp[x]<<endl;
    return 0;
}