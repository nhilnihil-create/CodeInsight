// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Fenwick Tree
struct FenwickTree {
    int length;
    vector<ll> node;
    FenwickTree (int N) : length(N), node(length + 1, 0) {}
    void add(int idx, ll val) {
        ++idx;
        while (idx <= length) {
            node[idx] += val;
            idx += (idx & (-idx));
        }
    }
    ll getsum(int idx) {
        ll ans = 0;
        while (idx) {
            ans += node[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
};

// Main
int main() {
    int n, q;
    cin >> n >> q;
    FenwickTree fw(n);
    rep(i, n) {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    rep(i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) fw.add(x, y);
        else cout << fw.getsum(y) - fw.getsum(x) << "\n";
    }
    return 0;
}
