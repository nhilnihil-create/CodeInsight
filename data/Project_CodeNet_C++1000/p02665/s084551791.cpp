#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n + 1], max[n + 1], min[n + 1];
    rep(i, n + 1) cin >> a[i];
    max[n] = min[n] = a[n];

    for (int i = n - 1; i >= 0; i--) {
        max[i] = max[i + 1] + a[i];
        min[i] = (min[i + 1] + 1) / 2 + a[i];
    }

    if (min[0] > 1) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0, p = 1;
    rep(i, n + 1) {
        ans += p;
        p = (p - a[i]) * 2;
        if (p > max[i + 1]) p = max[i + 1];
    }

    cout << ans << endl;
    return 0;
}
