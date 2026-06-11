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

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    vector<ll> left;
    vector<ll> right;
    for (ll i=0;i<=n-1;i++)
    {
        ll a=arr[i];
        left.push_back(i-a);
        right.push_back(i+a);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    ll ans=0;
    for (auto it=left.begin();it!=left.end();it++)
    {
       ans=ans+upper_bound(right.begin(),right.end(),*it)-lower_bound(right.begin(),right.end(),*it);
    }

    cout << ans << endl;
}