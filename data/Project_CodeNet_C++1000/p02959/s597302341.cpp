#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[100010];
int b[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=0;i<n+1;i++)cin>>a[i];

    for(int i=0;i<n;i++)cin>>b[i];

    ll ans=0;

    for(int i=0;i<n;i++)
    {
        ll s=min(a[i]+a[i+1],b[i]);
        ans+=s;
        s=min(a[i],b[i]);
        a[i]-=s;
        b[i]-=s;
        a[i+1]-=min(b[i],a[i+1]);
    }

    cout<<ans<<"\n";

    return 0;
}
