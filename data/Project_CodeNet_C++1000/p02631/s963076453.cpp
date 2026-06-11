#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    ll xo=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        xo^=a[i];
    }

    for(int i=0;i<n;i++)
    {   
        ll ans=xo^a[i];
        cout<<ans<<" ";
    }

    cout<<"\n";

    return 0;
}
