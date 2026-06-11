#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

ll modExp(ll b, int e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e /= 2;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vi sieve(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        sieve[i] += i;
        for (int j = i + i; j <= k; j += i) {
            sieve[j] -= sieve[i];
        }
    }

    map<int, ll> mrp;
    for (int i = 1; i <= k; i++) {
        mrp[k / i] += sieve[i];
    }

    ll ans = 0;
    for (auto& i : mrp) {
        ans = (ans + modExp(i.fi, n) * (i.se % mod)) % mod;
    }
    cout << ans;

    return 0;
}
