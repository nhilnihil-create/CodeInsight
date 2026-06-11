#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    ll ans=0;

    for(int i=1;i<n;i++)ans+=i;

    cout<<ans<<"\n";

    return 0;
}
