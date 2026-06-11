#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int d[1001],val[1001];
int dp[1001][(1<<12)+2],n,m;
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
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int sz,x;
        cin>>val[i]>>sz;
        while(sz--)
        {
            cin>>x;
            x--;
            d[i]|=(1<<x);
        }
    }
    int ans=fun(0,0);
    cout<<(ans>=1e9?-1:ans)<<endl;
	return 0;
}
