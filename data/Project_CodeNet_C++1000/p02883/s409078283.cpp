#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    ll lb = -1;
    ll ub = 1e12;
    sort(a.begin(), a.end(), greater<int>());
    sort(f.begin(), f.end());
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        ll count = 0;
        for (int i = 0; i < n; i++) {
            ll p = a[i] * f[i];
            if (p > mid) {
                count += a[i] - mid / f[i];
            }
        }
        if (count > k) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << ub << endl;
    return 0;
}
