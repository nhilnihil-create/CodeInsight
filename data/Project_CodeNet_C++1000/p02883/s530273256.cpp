#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

bool check(const vll& a, const vll& f, ll x, ll k) {
    ll sum = 0;
    rep(i, 0, a.size()) {
        if (a[i] * f[i] <= x) { continue; }

        sum += a[i] - x / f[i];
        if (sum > k) { return false; }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    ll sum_a = 0;
    vll a(n), f(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum_a += a[i];
    }
    rep(i, 0, n) { cin >> f[i]; }

    if (sum_a <= k) {
        cout << 0 << endl;
        return 0;
    }

    sort(all(a));
    sort(all(f), greater<ll>());

    ll max_ans = 0;
    rep(i, 0, n) { max_ans = max(max_ans, a[i] * f[i]); }

    // O(log(max_ans) * n)
    ll ng = 0, ok = max_ans;
    while (ng + 1 != ok) {
        ll mid = (ng + ok) / 2;
        if (check(a, f, mid, k)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}