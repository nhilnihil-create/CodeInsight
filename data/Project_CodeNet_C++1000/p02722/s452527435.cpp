#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool get(ll n, ll i) {
    if (i == 1) return 0;
    while (n % i == 0)n /= i;
    if (n == 1) return 1;
    return (n - 1) % i == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    int ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i)continue;
        ans += get(n, i);
        if (i * i != n) ans += get(n, n / i);
    }
    for (ll i = 1; i * i <= (n - 1); i++) {
        if ((n - 1) % i == 0 && n % i != 0) ans++;
        if (i * i == (n - 1)) continue;
        if ((n % ((n - 1) / i)) != 0 && ((n - 1) % ((n - 1) / i)) == 0)ans++;
    }
    cout << ans << endl;
    return 0;
}