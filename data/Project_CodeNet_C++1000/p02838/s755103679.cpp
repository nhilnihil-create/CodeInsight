#include <bits/stdc++.h>

#include <vector>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, 60) {
        ll x = 0;
        rep(j, n) if (a[j] >> i & 1)++ x;
        ll now = x * (n - x) % MOD;
        rep(j, i) now = now * 2 % MOD;
        ans += now;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
