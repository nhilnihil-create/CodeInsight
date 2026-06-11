#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define INF 1000000000000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin>>n;

    vector<ll> a,b;

    ll sn=sqrt(n);

    ll ans=INF;

    for(ll i=1;i<=sn;i++)
    {
        if(n%i==0)ans=min(ans,i+n/i-2);
    }

    cout<<ans<<"\n";

    return 0;
}
