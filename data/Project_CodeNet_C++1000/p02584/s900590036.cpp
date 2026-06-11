
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    ll dis=x/d;
    if (dis>=k)
    cout<<x-(k*d);
    else
    {
        x=x-(dis*d);
        k-=dis;
        if (k%2)
        {
            x-=d;
            x=abs(x);
        }
        cout<<x;
    }
}