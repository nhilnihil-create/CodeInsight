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
        ll a[n];

        for( int i=0 ; i< n ; i++ )
            cin>>a[i];

        sort( a,a+n );
        ll ans=0;
        for( int i=0 ; i<n-2 ; i++ )
        {
            for( int j=i+1 ; j<n-1 ; j++ )
            {
                if( a[j]>a[i] )
                {
                    for( int k=j+1 ; k<n ; k++ )
                    {
                        if( a[k]>a[j] && a[i]+a[j]>a[k] )
                        {
                            ans++ ;
                        }
                    }
                }
            }
        }

        cout<<ans;
    }

    return 0;
}










