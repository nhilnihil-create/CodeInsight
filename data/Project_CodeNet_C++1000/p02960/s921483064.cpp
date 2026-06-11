#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[100005][14];
string s;
ll n;
ll solve(ll pos,ll mo)
{
    if(pos==n)
    {
        return (mo==5);
    }
    if(dp[pos][mo]!=-1)
    return dp[pos][mo];
    ll ret=0;
    if(s[pos]=='?')
    {
    for(ll i=0;i<=9;i++)
    {
    ll di=i;
    ret=(ret%mod+solve(pos+1,(mo*10+di)%13)%mod)%mod;
    }
    }
    else
    {
        ll di=s[pos]-'0';
        ret=solve(pos+1,(mo*10+di)%13)%mod;
    }
    return dp[pos][mo]=ret;
}
int main()
{
    cin>>s;
    memset(dp,-1,sizeof dp);
    n=s.length();
    cout<<solve(0,0)<<endl;
}