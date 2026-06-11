#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fun(ll a)
{   ll ans=1;
    for(int i=1;i<=5;i++)
    {
        ans*=a;
    }
    return ans;
}
int main()
{
    ll x;
    cin>>x;
    for(ll i=-1000;i<=1000;i++)
    {
        for(ll j=-1000;j<=1000;j++)
        {
            if((fun(i)-fun(j))==x)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}