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
        int x,n;
        cin>>x>>n;

        if( n==0 )
        {
            cout<<x;
            return 0;
        }

        bool arr[200]={0};

        for( int i=0 ; i<n ; i++ )
        {
            int no;
            cin>>no;
            arr[no]=1;
        }

        if( !arr[x] )
        {
            cout<<x;
            return 0;
        }
        int la=-1;
        int ra=-1;
        int l,r;
        for( int left=x-1 ; left>=0 ; left-- )
        {
            if( !arr[left] )
            {
                l=left;
                la=x-l;
                break;
            }
        }

        for( int right=x+1 ; right<=101 ; right++ )
        {
            if( !arr[right] )
            {
                r=right;
                ra=r-x;
                break;
            }
        }

        if( la<=ra )
            cout<<l;
        else
            cout<<r;

    }
    return 0;
}
