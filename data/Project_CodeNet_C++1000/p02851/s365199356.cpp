#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

inline int mod(ll n, int k) {
    n %= k;
    if (n < 0) { n += k; }
    return (int)n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> cnt;
    vi memory;
    if (n >= k) {
        memory.reserve(k - 1);
        rep(i, 0, k - 1) { memory[i] = -1; }
    }

    ll sum = 0;
    ll ans = 0;

    rep(i, 0, n) {
        ll a;
        cin >> a;
        a %= k;

        sum = mod(sum + a, k);
        ++cnt[mod(a - sum + i, k)];

        if (n >= k) {
            if (memory[i % (k - 1)] != -1) { --cnt[memory[i % (k - 1)]]; }
            memory[i % (k - 1)] = mod(a - sum + i, k);
        }

        ans += cnt[mod(i + 1 - sum, k)];
    }

    cout << ans << endl;

    return 0;
}