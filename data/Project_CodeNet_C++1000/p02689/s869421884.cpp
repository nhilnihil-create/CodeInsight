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
        int n,m;
        cin>>n>>m;

        ll height[n+1];
        height[0]=-1;

        for( int i=1 ; i<=n ; i++ )
            cin>>height[i];

        int ans=0;

        bool chk[n+1];

        for( int i=0 ; i<=n ; i++ )
            chk[i]=1;

        for( int i=0 ; i<m ; i++ )
        {
            int a,b;

            cin>>a>>b;

            if( height[a]>height[b] )
                chk[b]=0;
            else if( height[b]>height[a] )
                chk[a]=0;
            else
                chk[a]=chk[b]=0;
        }



        for( int i=1 ; i<=n ; i++ )
        {
            if(chk[i])
                ans++;
        }

        cout<<ans;
    }
    return 0;
}










