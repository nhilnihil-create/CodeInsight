#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    return (((now * now) % mod) * n) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> cnt(k + 1);
    for (int i = 1; i <= k; i++) cnt[i] = my_pow(k / i, n);
    for (int i = k; i > 1; i--) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j != 0) continue;
            cnt[j] -= cnt[i];
            if (cnt[j] < 0) cnt[j] += mod;
            if (j * j != i && j != 1) cnt[i / j] -= cnt[i];
            if (cnt[i / j] < 0) cnt[i / j] += mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += cnt[i] * i;
        ans %= mod;
    }
    cout << ans;
    return 0;
}

