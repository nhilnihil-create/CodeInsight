#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll x;
    cin>>x;
    for(ll b = -1000; b<1000; b++)
    {
        for(ll a = b + 1; a<1000; a++)
        {
            ll b1 = b*b*b*b*b;
            ll a1 = a*a*a*a*a;
            if((a1 - b1) == x)
            {
                cout<<a<<" "<<b<<'\n';
                return 0;
            }
        }
    }
}