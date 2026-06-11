#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[5005];
ll p[5005];
bool vis[5005];
int tot=0;
vector<int>vec[5005];
map<int,ll>mp;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        tot++;
        int t=i;
        ll ans=0;
        while(vis[t]==0)
        {
            vis[t]=1;
            vec[tot].push_back(t);
            ans+=p[t];
            t=a[t];
        }
        mp[tot]=ans;
    }
//    for(int i=1;i<=tot;i++)
//    {
//        printf("val=%lld :",mp[i]);
//        for(auto  it:vec[i]) printf("%d ",it);
//        puts("");
//    }


    ll res=p[1];
    for(int i=1;i<=tot;i++)
    {
        for(int j=0;j<(int)vec[i].size();j++)
        {
            int t=vec[i][j];
            int step=0;
            ll ans=0;
            do
            {
                step++;
                t=a[t];
                ans+=p[t];
                if(mp[i]>0)
                {
                    res=max(res,ans+mp[i]*((k-step)/(int)vec[i].size()));
                }
               // printf("%+lld\n",ans);
                res=max(res,ans);
            }while(t!=vec[i][j]&&step<k);
        }
    }
    cout<<res;
    return 0;
}
