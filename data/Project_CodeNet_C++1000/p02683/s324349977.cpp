#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,m,x,ans=-1;
    cin>>n>>m>>x;
    vector<vector<int>> c(n,vector<int>(m+1));
    rep(i,n) rep(j,m+1) cin>>c[i][j];
    rep(i,1<<n)
    {
        vector<int> sum(m+1);
        rep(j,n)
        {
            if(i>>j&1)
            {
                rep(k,m+1) sum[k]+=c[j][k];
            }
        }
        int hantei=0;
        for(int k=1;k<m+1;k++) if(sum[k]<x) hantei=1;
        if(hantei==1) continue;
        if(ans==-1) ans=sum[0];
        else ans=min(ans,sum[0]);
    }
    cout<<ans;
}