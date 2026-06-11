#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,ans=0;
    cin>>n;
    ll a[n-1];
    for(i=0;i<n-1;i++)cin>>a[i];
    ans=a[0]+a[n-2];
    for(i=0;i<n-2;i++)
    {
        ans+=min(a[i],a[i+1]);
    }
    cout<<ans;
}
