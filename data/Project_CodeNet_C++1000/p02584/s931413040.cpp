#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    ll t=ceil(1.0*x/d);

    if(t>k)
    {
        cout<<(x-k*d);
    }
    else
    {
        if((k-t)%2==0)
        {
            ;
        }
        else
        {
            t--;

        }
        cout<<(abs(x-t*d));
    }
    return 0;
}
