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
        int n,m,k;
        cin>>n>>m>>k;

        ll a[n],b[m];

        for( int i=0 ; i<n ; i++ )
        {
            cin>>a[i];

            if( i>0 )
                a[i]=a[i]+a[i-1];
        }

        for( int i=0 ; i<m ; i++ )
        {
            cin>>b[i];

            if( i>0 )
                b[i]=b[i]+b[i-1];
        }

        if( k<a[0] && k<b[0] )
        {
            cout<<0;
            return 0;
        }
        if( k<b[0] )
        {
            auto it=upper_bound( a , a+n , k );
            it--;
            cout<<it-a+1;
            return 0;
        }

        if( k<a[0] )
        {
            auto it=upper_bound( b , b+n , k );
            it--;
            cout<<it-b+1;
            return 0;
        }


        auto it=upper_bound( b, b+m , k );
        it--;
        ll ans=it-b+1;

        for( int i=0 ; i<n ; i++ )
        {
            if( k<a[i] )
            break;

            ll rem=k-a[i];
            //3 4 240
            //60 90 120
            //80 150 80 150

            it = upper_bound( b , b+m , rem );
            it--;
            ll cur=it-b+1+(i+1);

            ans= max( ans, cur );
        }


        cout<<ans;
    }
    return 0;
}
