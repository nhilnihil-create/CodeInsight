#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n,m;
int a[1005],b[1005],ors[1005];
int dp[1005][(1<<12)+5];

int f(int idx,int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(idx==m)
        return 1e9;
    int &ret=dp[idx][mask];
    if(ret!=-1)
        return ret;
    ret=f(idx+1,mask);
    ret=min(f(idx+1,mask|ors[idx])+a[idx],ret);
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc>>st;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>a[i]>>b[i];
            for(int j=0; j<b[i]; j++)
            {
                int x;
                cin>>x;
                ors[i]|=(1<<(x-1));
            }
        }
        memset(dp,-1,sizeof dp);
        int ans=f(0,0);
        cout<<(ans<MAX?ans:-1)<<endl;
    }
    return 0;
}
