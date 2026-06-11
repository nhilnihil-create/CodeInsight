#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        ans += (n - 1) / i;
    }
    cout << ans;
}
