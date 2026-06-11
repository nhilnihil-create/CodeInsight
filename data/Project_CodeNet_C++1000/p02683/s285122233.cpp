#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,m,x,ans=-1;
    cin>>n>>m>>x;
    vector<vector<int>> c(n,vector<int>(m));
    rep(i,n) rep(j,m+1) cin>>c[i][j];
    rep(i,1<<n)
    {
        vector<int> allc(m+1);
        rep(j,n)
        {
            if(i>>j&1)
            {
                rep(k,m+1)
                {
                    allc[k]+=c[j][k];
                }
            }
        }
        int datam=0;
        rep(u,m)      //allc'kakuninn
        {
            if(allc[u+1]>=x) datam++;
        }
        if(datam==m&&ans==-1) ans=allc[0];
        else if (datam==m) ans=min(ans,allc[0]);
    }
    cout<<ans;
}