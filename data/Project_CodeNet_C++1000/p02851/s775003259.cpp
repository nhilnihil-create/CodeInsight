#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll pre[n+1]={0};
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i-1];
    for(int i=0;i<=n;i++)
        pre[i]=(pre[i]-i+k)%k;
    map<ll,ll>cnt;
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i-k>=0)cnt[pre[i-k]]--;
        ans+=cnt[pre[i]];
        cnt[pre[i]]++;
    }
    cout<<ans;
}