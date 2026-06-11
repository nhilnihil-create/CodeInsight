#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n - 1; i++) {
        if ((n - 1) % i == 0) {
            ll j = (n - 1) / i;
            ans++;
            if (i != j) ans++;
        }
    }
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll t = n;
            while (t % i == 0) t /= i;
            if (t % i == 1) ans++;
        }
    }
    cout << ans << endl;
}