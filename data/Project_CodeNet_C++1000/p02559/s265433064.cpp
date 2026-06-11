#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

template <typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n) : n(n), dat(n + 1, 0) {}

    T sum(int idx) {
        T res(0);
        for (int i = idx; i > 0; i -= i & -i) res += dat[i];
        return res;
    }

    T sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }

    void add(int idx, T x) {
        if (idx == 0) return;
        for (int i = idx; i <= n; i += i & -i) dat[i] += x;
    }

    int lower_bound(T x) {
        if (x <= 0) return T(0);
        int res = 0, r = 1;
        while (r < n) r <<= 1;
        for (; r > 0; r >>= 1) {
            if (res + r <= n && dat[res + r] < x) {
                x -= dat[res + r];
                res += r;
            }
        }
        return res + 1;
    }

    T sum0(int idx) {
        return sum(idx + 1);
    }

    T sum0(int l, int r) {
        return sum(r) - sum(l);
    }

    void add0(int idx, T x) {
        add(idx + 1, x);
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    BIT<ll> bit(n);
    int a;
    rep(i, n) {
        cin >> a;
        bit.add0(i, a);
    }
    int Q, p, x, l, r;
    rep(i, q) {
        cin >> Q;
        if (Q) {
            cin >> l >> r;
            cout << bit.sum0(l, r) << endl;
        } else {
            cin >> p >> x;
            bit.add0(p, x);
        }
    }
    return 0;
}