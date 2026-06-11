#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll >a(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    ll x=1000;
    for(ll i=0; i<n-1; i++)
    {
        int s=a[i];
        int t=a[i+1];
        if(s<t)
        {
            ll k=x/s;
            x=x%s;
            x+=k*t;
        }
    }
    cout<<x<<endl;
    return 0;
}
