#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll n,m;
    cin >> n >> m;

    multiset<ll> arr;
    for (ll i=0;i<=n-1;i++)
    {
        ll a;
        cin >> a;
        arr.insert(a);
    }

    for (ll i=0;i<=m-1;i++)
    {
        ll a=*prev(arr.end());
        arr.erase(prev(arr.end()));
        arr.insert(a/2);
    }

    ll ans=0;
    for (auto it=arr.begin();it!=arr.end();it++)
    {
        ans=ans+*it;
    }
    cout << ans << endl;

    return 0;
}