#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MOD 1000000007

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll a = 1;
    rep(i, n) {
        a *= 10;
        a %= MOD;
    }
    ll b = 1;
    rep(i, n) {
        b *= 9;
        b %= MOD;
    }
    b *= 2;
    b %= MOD;
    ll c = 1;
    rep(i, n) {
        c *= 8;
        c %= MOD;
    }
    ll ans = a - b;
    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }
    ans %= MOD;
    ans += c;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
