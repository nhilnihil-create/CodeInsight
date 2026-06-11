#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define  range(i, l, r) for (int i = (int)(l); i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = (int)(r) - 1; i >= (int)(l); --(i))

#define  whole(f, x, ...) ([&](decltype((x)) container) { return (f)(  begin(container),  end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)

#define endl '\n'
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr i32 mod   = 1e9 + 7;
constexpr i32 inf   = 1001001001;
constexpr i64 infll = 1001001001001001001ll;

constexpr int dx[] = {0, -1, 1, 0, -1, 1, -1, 1};
constexpr int dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};

struct IoSetup { IoSetup(int x = 15){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

template <typename T = i64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }

template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }

template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// clang-format on

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    F f;
    T ti;
    vector<T> dat;

    SegmentTree() {
    }
    SegmentTree(F f, T ti) : f(f), ti(ti) {
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }

    void build(const vector<T> &v) {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (int i = n - 1; i; i--)
            dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    void set_val(int k, T x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }

    T query(int a, int b) {
        if (a >= b) return ti;
        T vl = ti, vr = ti;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    int find(int st, C &check, T &acc, int k, int l, int r) {
        if (l + 1 == r) {
            acc = f(acc, dat[k]);
            return check(acc) ? k - n : -1;
        }
        int m = (l + r) >> 1;
        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl) return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }

    template <typename C>
    int find(int st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

void solver() {
    i32 N = input();
    auto p = make_vector(N + 2, inf);
    auto idx = make_vector(N + 1, 0);
    range(i, 1, N + 1) {
        cin >> p[i];
        idx[p[i]] = i;
    }

    auto lf = [](int a, int b) { return max(a, b); };
    auto rf = [](int a, int b) { return min(a, b); };
    SegmentTree<int> lidx(lf, 0), ridx(rf, N + 1);
    lidx.init(N + 2);
    ridx.init(N + 2);

    i64 ans = 0;
    rrange(i, 1, N + 1) {
        int j = idx[i];
        i64 b = lidx.query(0, j);
        i64 a = lidx.query(0, b);
        i64 c = ridx.query(j + 1, N + 1);
        i64 d = ridx.query(c + 1, N + 1);

        ans += ((c - j) * (b - a) + (j - b) * (d - c)) * i;

        lidx.set_val(j, j);
        ridx.set_val(j, j);
    }

    cout << ans << endl;
}

signed main(int argc, char *argv[]) {
    solver();
}
