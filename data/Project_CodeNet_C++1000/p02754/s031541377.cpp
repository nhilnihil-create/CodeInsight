#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,a,b;cin>>n>>a>>b;

    ll ans=(n/(a+b))*a;
    n%=a+b;

    ans+=min(n,a);

    cout<<ans<<"\n";

    return 0;
}
