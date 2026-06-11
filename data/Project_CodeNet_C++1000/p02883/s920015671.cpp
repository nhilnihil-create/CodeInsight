#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n,k;
    cin >> n >> k;

    vector<ll> a(n), f(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());

    ll ng = -1, ok = 1e12 + 1;
    ll ans = 0;

    while(ok - ng > 1) {
        ll mid = (ng + ok) / 2;

        ll tot = 0;
        for (int i = 0; i < n; i++) {
            ll c = mid / f[i];
            tot += max(0LL, a[i] - c);
        }

        if(tot <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
}