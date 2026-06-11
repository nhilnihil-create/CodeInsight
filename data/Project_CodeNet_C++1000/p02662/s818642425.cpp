#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e3+5;
const int p=998244353;
int po[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        po[i]=u;
        u*=2;
        u%=p;
    }
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans[s+1];
    for(int i=0;i<=s;++i)
    {
        ans[i]=0;
    }
    ans[0]=1;
    for(int i=0;i<n;++i)
    {
        int curr[s+1];
        for(int j=0;j<=s;++j)
        {
            curr[j]=ans[j];
        }
        for(int j=s;j>=0;j--)
        {
            if((a[i]+j)<=s)
            {
                ans[a[i]+j]+=ans[j];
            }
        }
        for(int j=0;j<=s;++j)
        {
            ans[j]+=curr[j];
            ans[j]%=p;
            //cout<<j<<" "<<ans[j]<<endl;
        }
        //cout<<endl;
    }
    cout<<ans[s];
    return 0;
}
