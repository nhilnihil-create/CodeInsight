#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e3+5;
const int mod=1e9+7;
ll dp[maxn][maxn];
struct ac
{
    ll p,v;
};
ac a[maxn];
bool cmp(ac a,ac b)
{
    return a.v>b.v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].p=i;
    }
    sort(a+1,a+1+n,cmp);
    ll ans=-1;
    for(int la=1;la<n;la++) //已放置到第几个数
    {
        for(int s=0;s<=la;s++)
        {
            int j=n-la+s;
            int i=s+1;
            if(j+1<=n)
            dp[i][j]=max(dp[i][j],dp[i][j+1]+a[la].v*abs(j+1-a[la].p));
            if(i-1>=1)
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[la].v*abs(a[la].p-(i-1)));
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][i]+a[n].v*abs(a[n].p-i));
    }
    cout<<ans<<'\n';


}
