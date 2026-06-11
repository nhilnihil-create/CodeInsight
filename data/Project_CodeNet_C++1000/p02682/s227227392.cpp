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
        ll a,b,c,k;
        cin>>a>>b>>c>>k;

        if( k<=a )
            cout<<k;
        else if( k<=a+b )
            cout<<a;
        else
        {
            ll ans=a-(k-(a+b));
            cout<<ans;
        }
    }
    return 0;
}










