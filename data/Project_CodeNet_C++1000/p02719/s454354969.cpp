#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,k;
    cin>>n>>k;

    ll l=n%k;

    if(l>k/2)cout<<k-l<<"\n";
    else cout<<l<<"\n";

    return 0;
}
