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
        ll n,d;
        cin>>n>>d;
        ll ans=0;

        for( int i=0 ; i<n ; i++ )
        {
            ll p,q;
            cin>>p>>q;
            ll sqr=( (p*p)+(q*q) );
            if( d*d>=sqr )
                ans++;
        }
        cout<<ans;
    }

    return 0;
}










