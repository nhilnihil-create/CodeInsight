#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

template <typename Operator>
struct SegmentTree {
    Operator OP;
    using TypeNode = decltype(OP.NodeE);
    int length, num;
    vector<TypeNode> node;
    SegmentTree (int N) {
        num = N;
        length = 1;
        while (length < N) length <<= 1;
        node.assign(length << 1, OP.NodeE);
    }
    SegmentTree (vector<TypeNode> &vec) {
        num = SZ(vec);
        length = 1;
        while (length < vec.size()) length <<= 1;
        node.assign(2 * length, OP.NodeE);
        for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
        for (int i = length - 1; i > 0; --i) node[i] = OP.func(node[(i << 1) + 0], node[(i << 1) + 1]);
    }
    void update(int idx, TypeNode val) {
        idx += length;
        node[idx] = OP.change(node[idx], val);
        while (idx >>= 1) node[idx] = OP.func(node[(idx << 1) + 0], node[(idx << 1) + 1]);
    }
    TypeNode get(int l, int r) {
        if (l < 0 || r < 0 || l > num || r > num) return OP.NodeE;
        l += length;
        r += length;
        TypeNode vl = OP.NodeE, vr = OP.NodeE;
        while (r > l) {
            if (l & 1) vl = OP.func(vl, node[l++]);
            if (r & 1) vr = OP.func(node[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return OP.func(vl, vr);
    }
};

template <typename NodeType = int>
struct hoge {
    NodeType NodeE = 0;
    NodeType func(NodeType x, NodeType y) {return max(x, y);}
    NodeType change(NodeType x, NodeType y) {return y;}
};


int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    REP(i, n) {
        cin >> p[i];
        --p[i];
    }
    
    SegmentTree<hoge<>> ST(p);
    ll ans = 0;
    REP(i, n) {
        int a = 0, b = 0, c = 0, d = 0, l = 0, r = 0;
        l = -1; r = i;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (ST.get(m, i) > p[i]) l = m;
            else r = m;
        }
        b = l;
        l = -1; r = b;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (ST.get(m, b) > p[i]) l = m;
            else r = m;
        }
        a = l;
        l = i; r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (ST.get(i, m) > p[i]) r = m;
            else l = m;
        }
        c = l;
        l = c; r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (ST.get(c + 1, m) > p[i]) r = m;
            else l = m;
        }
        d = l;
        ans += ((ll)(i - b) * (d - c) + (ll)(c - i) * (b - a)) * p[i];
    }
    
    ans += (ll)n * (n - 1) / 2;
    cout << ans << "\n";
    return 0;
}
