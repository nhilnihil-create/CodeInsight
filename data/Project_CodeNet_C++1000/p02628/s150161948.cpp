#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int t=1;
    //cin>>t;

    while( t-- )
    {
        int n,k;
        cin>>n>>k;

        int p[n];

        for( int i=0 ; i<n ; i++ )
            cin>>p[i];

        sort( p,p+n );

        ll ans=0;
        for( int i=0 ; i<k ; i++ )
            ans+=p[i];

        cout<<ans;
    }
    return 0;
}
