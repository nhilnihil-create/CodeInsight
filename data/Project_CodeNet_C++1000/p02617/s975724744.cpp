#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) ans += i * (i + 1) / 2;
    for (ll i = 1; i < n; i++) {
        ll a, b, c, d;
        cin >> c >> d;
        a = min(c, d);
        b = max(c, d);
        ans -= a * (n - b + 1);
    }
    cout << ans;
}