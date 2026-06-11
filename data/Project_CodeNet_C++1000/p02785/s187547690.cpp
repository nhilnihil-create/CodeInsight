#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll res = 0;
    for(int i = n - k - 1; i >= 0; --i)
        res += a[i];

    cout << res << "\n";
    return 0;
}