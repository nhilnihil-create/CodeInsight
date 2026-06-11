#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf (ll)(1e18)
#define mod 1000000007

int main()
{
    int t=1;
    //cin>>t;

    while( t-- )
    {
        int n;
        cin>>n;

        map<ll,ll> p;
        ll m[n+1];

        for( int i=1 ; i<=n ; i++ )
        {
            ll x;
            cin>>x;
            m[i]=i-x;
            p[i+x]++;
        }

        ll ans=0;
        for( int i=1 ; i<=n ; i++ )
        {
            ans+=p[m[i]];
        }

        cout<<ans;
    }
    return 0;
}










