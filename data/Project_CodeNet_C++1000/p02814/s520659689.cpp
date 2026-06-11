#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,m;cin>>n>>m;
    vector<ll> a(n);

    cin>>a[0];
    int r=1;
    for(ll ia=a[0];ia%2==0;ia/=2)r*=2;
    ll g=a[0];
    bool c=r!=1;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        if(!(a[i]%r==0&&(a[i]/r)%2==1))c=false;
        g=lcm(g,a[i]);
    }

    ll ans=0;

    if(c)
    {
        ans=(m+(g/2))/g;
    }

    cout<<ans<<"\n";

    return 0;
}
