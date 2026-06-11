#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
const int mxN = 2e5;
map<ll, ll> mp;

int main()
{
    ll n, a[mxN], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += mp[i - a[i]];
        mp[i + a[i]]++;
    }
    cout << ans << "\n";
}