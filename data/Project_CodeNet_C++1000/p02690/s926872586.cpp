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
        ll x;
        cin>>x;

        for( int i=-120 ; i<=120 ; i++ )
        {
            for( int j=-120 ; j<=120 ; j++ )
            {
                ll ans=pow( i,5 )-pow( j,5 );
                if( ans==x )
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}










