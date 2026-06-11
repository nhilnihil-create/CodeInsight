#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 998244353,
          iv2 = 499122177;

ll modExp2(int e) {
    ll r = 1;
    for (ll b = 2; e; e >>= 1, b = b * b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, s;
    cin >> n >> s;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<ll> dp(s + 1);
    dp[0] = modExp2(n);

    for (int i : a) {
        for (int j = s; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i] * iv2) % mod;
        }
    }

    cout << dp.back();
}
