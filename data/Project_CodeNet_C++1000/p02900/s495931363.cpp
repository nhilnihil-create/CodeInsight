#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll a, b;
    cin >> a >> b;

    ll g = __gcd(a, b);
    ll ans = 1;

    for (ll i = 2; i * i <= g; i++) {
        if (g % i == 0) ans++;
        while (g % i == 0) g /= i;
    }

    if (g == 1)
        cout << ans << endl;
    else
        cout << ans + 1 << endl;
    return 0;
}
