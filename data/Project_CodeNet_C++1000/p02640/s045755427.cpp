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
        int x,y;
        cin>>x>>y;

        if( y%2==0 )
        {
            if( x*2<=y && y<=x*4 )
                cout<<"Yes";
            else
                cout<<"No";
        }
        else
            cout<<"No";
    }
    return 0;
}
