#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,j,x=-1,ans=0;
    cin>>n;
    ll a[n],b[n],c[n-1];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    for(i=0;i<n-1;i++)cin>>c[i];
    for(i=0;i<n;i++)
    {
        if(x==a[i]-1)ans+=c[a[i]-2];
        ans+=b[a[i]-1];
        x=a[i];
     //   cout<<ans<<" ";
    }
    cout<<ans;
}
