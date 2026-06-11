#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.rbegin(), h.rend());
    for (int i = 0; i < n; ++i) {
        if (i <= k - 1)
            continue;
        ans += h[i];
    }
    cout << ans << endl;
    return 0;
}