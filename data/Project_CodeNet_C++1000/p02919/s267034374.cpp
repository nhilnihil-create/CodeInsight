#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

template <typename M> struct SegmentTree {
    using T = typename M::T;
    int n;
    vector<T> dat;
    SegmentTree() {}
    SegmentTree(int n_) { init(n_); }
    SegmentTree(const vector<T> &v) { build(v); }
    void init(int n_) {
        n = 1;
        while(n < n_)
            n <<= 1;
        dat.assign(n << 1, M::ti());
    }
    void build(const vector<T> &v) {
        int n_ = v.size();
        init(n_);
        for(int i = 0; i < n_; i++)
            dat[n + i] = v[i];
        for(int i = n - 1; i; i--)
            dat[i] = M::f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
    void set_val(int k, T x) {
        dat[k += n] = x;
        while(k >>= 1)
            dat[k] = M::f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }
    //[a,b)
    T query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if(r < 0)
            r = n;
        if(r <= a || b <= l)
            return M::ti();
        if(a <= l && r <= b)
            return dat[k];
        T vl = query(a, b, k * 2, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
        return M::f(vl, vr);
    }
    T operator[](const int &k) const { return dat[k + n]; }
};

struct Rminmin2maxmax2Q {
    struct T {
        ll min, min2, max, max2;
    };
    static T ti() { return {INT_MAX, INT_MAX, -1, -1}; }
    static T f(const T &l, const T &r) {
        return {min(l.min, r.min), min({max(l.min, r.min), l.min2, r.min2}),
                max(l.max, r.max), max({min(l.max, r.max), l.max2, r.max2})};
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int idx[N];
    for(int i = 0; i < N; i++) {
        int P;
        cin >> P;
        idx[--P] = i;
    }
    vector<Rminmin2maxmax2Q::T> v(N);
    for(int i = 0; i < N; i++) {
        v[i] = {i, INT_MAX, i, -1};
    }
    SegmentTree<Rminmin2maxmax2Q> seg(v);
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        auto left = seg.query(0, idx[i]);
        auto right = seg.query(idx[i] + 1, N);
        if(right.min == INT_MAX)
            right.min = N;
        if(right.min2 == INT_MAX)
            right.min2 = N;
        ans += (i + 1) * (left.max - left.max2) * (right.min - idx[i]);
        ans += (i + 1) * (right.min2 - right.min) * (idx[i] - left.max);
        seg.set_val(idx[i], Rminmin2maxmax2Q::ti());
    }
    cout << ans << endl;
    return 0;
}