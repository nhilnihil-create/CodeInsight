#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int x=1;
    //cin>>t;
    while( x-- )
    {
        ll n;
        cin>>n;

        if( n%1000==0 )
            cout<<0;
        else
        {
            int rem=n%1000;
            cout<<1000-rem;
        }
    }
    return 0;
}
