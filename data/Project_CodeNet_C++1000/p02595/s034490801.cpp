#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k, cnt=0, p ;
    cin>>n>>k;
    for( ll i=0; i<n; i++ )
    {
        ll x, y ;
        cin >> x >> y ;
        p = (x*x) + (y*y);
        if( p <= k*k)
            cnt++;

    }
    cout<<cnt<<endl;
    return 0;
}
