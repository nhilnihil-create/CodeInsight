#include <bits/stdc++.h>
using namespace std;
int d[1001],val[1001];
int dp[1001][(1<<12)],n,m,sz,x;
int fun(int idx,int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(idx==m) return 1e9;
    int &ret=dp[idx][mask];
    if(~ret) return ret;
    return ret=min(val[idx]+fun(idx+1,mask|d[idx]),fun(idx+1,mask));
}
signed main()
{

    memset(dp,-1,sizeof dp);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {

       scanf("%d%d",&val[i],&sz);
        while(sz--)
        {
            scanf("%d",&x);
            d[i]|=(1<<(x-1));
        }
    }
    int ans=fun(0,0);
    printf("%d",(ans>=1e9?-1:ans));
	return 0;
}
