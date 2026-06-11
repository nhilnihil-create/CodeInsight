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
        int n,m,x;
        cin>>n>>m>>x;

        int cost[n];
        int skill[n][m];

        for( int i=0 ; i<n ; i++ )
        {
            cin>>cost[i];

            for( int j=0 ; j<m ; j++ )
                cin>>skill[i][j];
        }

        bool f=1;

        for( int i=0 ; i<m ; i++ )
        {
            int cur=0;
            for( int j=0 ; j<n ; j++ )
            {
                cur+=skill[j][i];
            }
            if( cur<x )
            {
                f=0;
                break;
            }
        }

        if(!f)
        {
            cout<<-1<<endl;
            return 0;
        }

        ll ans=inf;

        for( int i=1 ; i<(1<<n) ; i++ )
        {
            int temp=i;
            ll total[m]={0};
            int idx=0;
            ll cc=0;
            while( temp )
            {
                bool active=temp%2;

                if(active)
                {
                    cc+=cost[idx];
                    for( int j=0 ; j<m ; j++ )
                        total[j]+=skill[idx][j];
                }
                temp/=2;
                idx++;

            }

            bool chk=1;

            for( int j=0 ; j<m ; j++ )
            {
                if( total[j]<x )
                {
                    chk=0;
                    break;
                }
            }

            if( chk )
                ans=min(ans,cc);
        }
        cout<<ans;
    }
    return 0;
}










