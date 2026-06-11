#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,a,b;
    cin>>n>>a>>b;

    ll ans=n/(a+b);
    ans*=a;
    ans+=min(n%(a+b),a);

    cout<<ans<<"\n";

    return 0;
}
