#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,need;
int a[15][15];
int cost[20];
int dp[20][1<<15];
int func(int pos,int mask)
{
    if(pos>n)
    {
        int tcost=0;
        for(int i=1; i<=m; i++)
        {
            int sm=0;
            for(int j=1; j<=n; j++)
            {

                if(mask&(1<<(j-1)))
                {
                    sm+=a[j][i];
                    if(i==1)
                    tcost+=cost[j];
                }
            }
            if(sm<need) return INT_MAX;
        }
        return tcost;
    }
    int &r=dp[pos][mask];
    if(r!=-1) return r;

    int x=func(pos+1,mask|(1<<pos));
    int y=func(pos+1,mask);
    r=min(x,y);
    return dp[pos][mask]=r;
}
int main()
{
    cin>>n>>m>>need;
    for(int i=1; i<=n; i++)
    {
        int c;
        cin>>c;
        cost[i]=c;
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    int ans=func(0,0);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans<<endl;
}
