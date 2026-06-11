#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll mod = 998244353;

ll rep_pow(int n, int p) { // n^p
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll t = rep_pow(n, p / 2);
        return t * t % mod;
    } else {
        return n * rep_pow(n, p - 1) % mod;
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> count(n, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (i == 0 && d != 0) {
            cout << 0 << endl;
            return 0;
        }
        count[d]++;
        mx = max(mx, d);
    }
    if (count[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        ans *= rep_pow(count[i - 1], count[i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
