#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    vector<T> data;

    BinaryIndexedTree() = default;

    explicit BinaryIndexedTree(size_t sz) : data(sz + 1, 0) {}

    explicit BinaryIndexedTree(const vector<T> &vs) : data(vs.size() + 1, 0) {
        for (size_t i = 0; i < vs.size(); i++) data[i + 1] = vs[i];
        for (size_t i = 1; i < data.size(); i++) {
            size_t j = i + (i & -i);
            if (j < data.size()) data[j] += data[i];
        }
    }

    void add(int k, const T &x) {
        for (++k; k < (int)data.size(); k += k & -k) data[k] += x;
    }

    T query(int k) const {
        T ret = T();
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    T query(int l, int r) const { return query(r - 1) - query(l - 1); }

    int lower_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
            if (i + k < data.size() && data[i + k] < x) {
                x -= data[i + k];
                i += k;
            }
        }
        return i;
    }

    int upper_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
            if (i + k < data.size() && data[i + k] <= x) {
                x -= data[i + k];
                i += k;
            }
        }
        return i;
    }
};

using i64 = int64_t;

int main() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;
    BinaryIndexedTree<i64> bit(a);
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
            bit.add(x, y);
        else
            cout << bit.query(x, y) << '\n';
    }
}