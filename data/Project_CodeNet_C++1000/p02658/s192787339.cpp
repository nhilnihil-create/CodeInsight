#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) ans = 0;
    }
    if (ans != 0) {
        for (int i = 0; i < n; i++) {
            if (a[i] > (ll)1e18 / ans) {
                ans = -1;
                break;
            } else {
                ans *= a[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}