#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int main()
{
    ll n; cin>>n; ll a[n+2]; for(ll i=1;i<=n;i++) cin>>a[i];
    ll c=0;
    for(ll i=1;i<=n;i++)
    {
        if(a[i]%2!=0 && i%2!=0) c++;
    }
    cout<<c;
}
