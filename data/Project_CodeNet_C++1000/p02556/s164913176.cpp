#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    ll n,i,x,y,s=1e9+5;
    cin>>n;
    ll a[n+1],b[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        a[i]=x+y;b[i]=(s-x)+y;
    }
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    ll ans=max(a[n]-a[1],b[n]-b[1]);
    cout<<ans<<endl;
}
