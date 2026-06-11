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
        int n,k;
        cin>>n>>k;

        bool snuke[n+1]={0};
        for( int i=0 ; i<k ; i++ )
        {
            int d;
            cin>>d;

            for( int j=0 ; j<d ; j++ )
            {
                int a;
                cin>>a;
                snuke[a]=1;
            }
        }

        int ans=0;
        for( int i=1 ; i<=n ; i++ )
        {
            if(!snuke[i])
                ans++;
        }

        cout<<ans;
    }
    return 0;
}










