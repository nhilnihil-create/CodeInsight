#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1LL; i <= n; i += 1LL) {
        ans += i * (n - i + 1LL);
    }
    for (ll i = 1LL; i <= n - 1; i += 1LL) {
        ll a, b;
        cin >> a >> b;
        ans -= (a > b ? b : a) * (n - (a > b ? a : b) + 1);
    }
    cout << ans << endl;
    return 0;
}