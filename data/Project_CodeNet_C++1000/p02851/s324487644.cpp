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

    // 1-indexed.
    vi a(n + 1, 0), sum(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] %= k;
        sum[i] = (a[i] + sum[i - 1]) % k;
    }

    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> cnt;
    queue<int> mem;

    ll ans = 0;

    rep(i, 0, n + 1) {
        int tmp = mod(sum[i] - i, k);

        ans += cnt[tmp];
        ++cnt[tmp];
        mem.push(tmp);

        if (n >= k) {
            if ((int)mem.size() == k) {
                --cnt[mem.front()];
                mem.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}