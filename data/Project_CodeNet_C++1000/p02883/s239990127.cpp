#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
    ll ub = 0;
    for (int i = 0; i < n; i++) {
        ub = max(ub, a[i] * f[i]);
    }
    ll lb = -1;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        ll train = 0;
        for (int i = 0; i < n; i++) {
            ll a_border = mid / f[i];
            train += max(a[i] - a_border, 0ll);
        }
        if (train <= k) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << ub;
    return 0;
}