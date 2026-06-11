#include <iostream>
#include <vector>
#include <atcoder/segtree>
using namespace std;
int64_t op(int64_t a, int64_t b) {
    return a + b;
}
int64_t e() {
    return (int64_t)0;
}
int main() {
    int64_t n, q;
    cin >> n >> q;
    vector<int64_t> a(n);
    for (auto& i : a) cin >> i;
    atcoder::segtree<int64_t, op, e> seg(a);
    for (int64_t i = 0; i < q; i++) {
        int64_t t, p, x;
        cin >> t >> p >> x;
        if (t == 0) {
            auto v = seg.get(p);
            seg.set(p, v + x);
        }
        else if (t == 1) {
            cout << seg.prod(p, x) << endl;
        }
    }
}
