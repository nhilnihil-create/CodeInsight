#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define INF 1000000000000000000

ll a[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    ll ans=INF;

    for(int i=1;i<n;i++)
    {
        ans=min(ans,abs(a[n]-a[i]-a[i]));
        if(a[n]-a[i]<a[i])break;
    }

    cout<<ans<<"\n";

    return 0;
}
