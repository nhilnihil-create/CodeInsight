#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll x;cin>>x;

    ll ans=0;

    ans=(x/500)*1000;

    x=x%500;

    ans+=(x/5)*5;

    cout<<ans<<"\n";

    return 0;
}
