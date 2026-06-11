#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;
int main()
{
    ll n,d;
    cin>>n>>d;
    ll count=0;
    ll x,y;
    for(ll i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x*x + y*y <= d*d)
        count++;
    }
    cout<<count<<endl;
    return 0;
}
