#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define pi 3.141592653589793238

int main()
{
    int t=1;
    //cin>>t;


    while( t-- )
    {
        ll x;
        cin>>x;

        ll p=100;
        int ans=0;
        while(p<x)
        {
            p=p+(p/100);
            ans++;
        }

        cout<<ans;

    }
    return 0;
}
