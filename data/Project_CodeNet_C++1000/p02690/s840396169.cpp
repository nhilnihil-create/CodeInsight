#include<bits/stdc++.h>
#define pb push_back
#define vl vector
#define ll long long
#define ff first
#define ss second
#define fast std::ios::sync_with_stdio(false)
using namespace std;

ll ras(ll a)
{
    return a*a*a*a*a;
}

int main()
{
    fast;
    ll x;
    cin>>x;
    ll i,j;
    for(i=-200;i<=200;i++)
    {
        for(j=-200;j<=200;j++)
        {
            if(ras(i)-ras(j)==x)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}