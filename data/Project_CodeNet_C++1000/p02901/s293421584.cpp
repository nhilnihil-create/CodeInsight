#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int cost[30005];
int submask[30005];
int dp[5000][3001];
int solve(int mask,int index)
{
    if(index==m)
    {
        if(mask==pow(2,n)-1)
        return 0;
        else
        return 1000000000;
    }
    if(dp[mask][index]!=-1)
    return dp[mask][index];
    int ans=min(solve(mask,index+1),solve(mask|submask[index],index+1)+cost[index]);
    return dp[mask][index]=ans;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        cost[i]=x;
        submask[i]=0;
        while(y--)
        {
            cin>>z;
            submask[i]+=(1<<(z-1));
        }
    }
    memset(dp,-1,sizeof dp);
    int ans=solve(0,0);
    if(ans==1000000000)
    cout<<-1<<'\n';
    else
    cout<<ans<<'\n';
}