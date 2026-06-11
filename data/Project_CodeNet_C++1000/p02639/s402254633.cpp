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
        int a[5];
        int ans;

        for( int i=0 ; i<5 ; i++ )
        {
            cin>>a[i];
            if( a[i]==0 )
                ans=i+1;
        }
        cout<<ans;

    }
    return 0;
}
