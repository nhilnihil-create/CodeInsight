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
        ll n;
        cin>>n;

        ll a[n];

        for( int i=0 ; i<n ; i++ )
            cin>>a[i];

        sort( a,a+n );

        ll ans=a[n-1];


        ll left=(n-2),i=n-2;

        if( left%2==0 )
        {
            left=left/2;
            while( left-- )
            {
                ans+=2*a[i];
                i--;
            }
        }
        else
        {
            left=left/2;
            while( left-- )
            {
                ans+=2*a[i];
                i--;
            }
            ans+=a[i];
        }
        cout<<ans;
    }
    return 0;
}
