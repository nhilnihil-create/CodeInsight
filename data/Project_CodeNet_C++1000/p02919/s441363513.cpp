#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    int sz;
    vector< Monoid > seg;
    const F f;
    const Monoid M1;
    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }
    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }
    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }
    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if(check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }
    template< typename C >
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }
    template< typename C >
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1) {
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> p(n); rep (i, n) cin >> p[i];
    SegmentTree<ll> seg(n, [](int a, int b){ return max(a, b); }, 0);
    rep (i, n) seg.update(i, p[i]);
    ll ans = 0;
    ll ng, ok, l1, l0, r0, r1;
    rep (i, n) {
        // left : x >= p[i]
        ng = -1, ok = i;
        while (ok - ng > 1) {
            int med = (ok + ng) / 2;
            (seg.query(med, i) < p[i] ? ok : ng) = med;
        }
        l0 = ok; ng = -1;
        while (ok - ng > 1) {
            int med = (ok + ng) / 2;
            (seg.query(med, l0 - 1) < p[i] ? ok : ng) = med;
        }
        l1 = ok;

        // right : p[i] < x
        ng = n + 1, ok = i + 1;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            (seg.query(i + 1, med) <= p[i] ? ok : ng) = med;
        }
        r0 = ok; ng = n + 1;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            (seg.query(r0 + 1, med) <= p[i] ? ok : ng) = med;
        }
        r1 = ok;
        ans += p[i] * ((i - l0 + 1) * (r1 - r0) + (l0 - l1) * (r0 - i));
    }
    cout << ans << "\n";
    return 0;
}