#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (ll i = ((ll)(n)-1); i >= 0; --i)
#define rreps(i, n) for (ll i = ((ll)(n)); i > 0; --i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repc2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;

template <typename T>
struct BIT {
    int n;
    vector<T> data;
    BIT(int n) : n(n + 1), data(n + 1, 0) {}
    void add(int i, T x) {
        for (int j = i; j < n; j += (j & -j)) {
            data[j] += x;
        }
    }
    T sum(int i) {
        T s(0);
        for (int j = i; j > 0; j -= (j & -j)) {
            s += data[j];
        }
        return s;
    }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int n, q;

int main() {
    scanf("%d%d", &n, &q);
    BIT<ll> bit(n);
    reps(i, n) {
        ll a;
        scanf("%lld", &a);
        bit.add(i, a);
    }
    rep(i, q) {
        int c, a, b;
        scanf("%d%d%d", &c, &a, &b);
        if (c == 0) {
            bit.add(a + 1, b);
        } else {
            printf("%lld\n", bit.sum(a + 1, b));
        }
    }
    return 0;
}