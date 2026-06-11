#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

long long int mod_pow(long long int x, long long int n, long long int p) {
    long long int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << 0 << endl;
    } else {
        ll cnt = 0, cnt2 = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (a[i] > a[j]) {
                    cnt++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] < a[j]) {
                    cnt2++;
                }
            }
        }

        ll ans = 0;

        cnt *= k;
        cnt %= mod;
        ll t = k * (k - 1);
        t %= mod;
        t *= mod_pow(2, mod - 2, mod);
        t %= mod;
        cnt2 *= t;
        cnt2 %= mod;
        ans = cnt + cnt2;
        ans %= mod;
        cout << ans << endl;
    }
}