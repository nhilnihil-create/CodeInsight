#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] == 'W' || s[n * 2 - 1] == 'H') {
        cout << 0 << endl;
        return 0;
    }

    bool left_right[n * 2] = {};
    left_right[0] = true;

    repd(i, 1, 2 * n) {
        if (s[i] == s[i - 1]) {
            left_right[i] = !left_right[i - 1];
        } else {
            left_right[i] = left_right[i - 1];
        }
    }

    ll count = 0;
    rep(i, 2 * n) {
        if (left_right[i]) {
            count++;
        } else {
            count--;
        }
    }
    if (count != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep(i, 2 * n) {
        if (left_right[i]) {
            count++;
        } else {
            ans *= count;
            count--;
            ans %= mod;
        }
    }

    ll base = 1;
    repd(i, 1, n + 1) {
        base *= i;
        base %= mod;
    }

    ans *= base;
    ans %= mod;

    cout << ans << endl;

    return 0;
}

