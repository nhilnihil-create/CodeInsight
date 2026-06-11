#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
ll a[2000005];
int main()
{
    // Ai+Aj = j-i equivalent to Ai+i= j-Aj
    ll n;
    cin >> n;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        mp[a[i]+i]++;
    }
    ll ans=0;
    for(ll j=1;j<=n;j++)
    {
        ans+=mp[j-a[j]];
    }
    cout << ans << endl;
}
