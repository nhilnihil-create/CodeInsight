#include <iostream>
#include <cstdio>
#include <math.h>
#define ll long long int
using namespace std;

int main()
{
    //freopen("a.inp","r",stdin);
    ll n,d,dem=0,m, x, y;
    cin>>n>>d;
    for(ll i=1; i<=n; ++i)
    {
        cin>>x>>y;
        m= x*x + y*y;
        //cout<<sqrt(m)<<endl;
        if( sqrt(m)<=d ) dem++;
    }
    cout<<dem;
    return 0;
}
