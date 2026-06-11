#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int p[5005],c[5005];
int main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=n;++i)
        cin>>c[i];
    ll ans=-1e18;
    for(int i=1;i<=n;++i)
    {
        vector<int> v;
        bool vis[5005]={0};
        int now=i;
        while(1)
        {
            if(vis[now]) break;
            vis[now]=true;
            v.push_back(now);
            now=p[now];
        }
        int len=v.size();
        if(k>len)
        {
            ll loopsum=0;
            for(int j=0;j<len;++j)
                loopsum+=c[p[v[j]]];
            if(loopsum>0)
            {
                ll loopcnt=k/len-1;
                ll kk=k-len*loopcnt;
                ll tmp=loopcnt*loopsum;
                int index=0;
                while(kk)
                {
                    tmp+=c[p[v[index]]];
                    ans=max(ans,tmp);
                    index=(index+1)%len;
                    kk--;
                }
            }
            else
            {
                ll tmp=0;
                for(int j=0;j<len;++j)
                    tmp+=c[p[v[j]]],ans=max(ans,tmp);
            }
        }
        else
        {
            ll tmp=0;
            for(int j=0;j<k;++j)
                tmp+=c[p[v[j]]],ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}