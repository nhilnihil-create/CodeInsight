#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll l, r, mn = 1e18;
    cin >> l >> r;
    for(ll i = l; i <= min(l + 2019, r); i++)
        for(ll j = i + 1; j <= min(l + 2019, r); j++)
            mn = min(mn, (i * j) % 2019);
    cout << mn;
    return 0;
}
