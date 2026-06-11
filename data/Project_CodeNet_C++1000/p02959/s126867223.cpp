#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,j,ans=0;
    cin>>n;
    ll a[n+1],b[n];
    for(i=0;i<n+1;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    for(i=n-1;i>=0;i--)
    {
        ans+=min(a[i+1],b[i]);
        b[i]-=a[i+1];
        if(b[i]<1)continue;
        ans+=min(a[i],b[i]);
        if(b[i]>a[i])a[i]=0;
        else a[i]-=b[i];
    }
    cout<<ans;
}
