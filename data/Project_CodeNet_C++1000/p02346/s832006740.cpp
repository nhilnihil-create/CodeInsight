#include <bits/stdc++.h>

using namespace std;

//////////////////////////////////////////////////
class SegmentTree
{
public:
    typedef long long Int;
    static const Int DEFAULT_VALUE = 0; 
    vector<Int> data;
    Int N;

    inline Int func(Int x, Int y) {
        return x + y;
    }

    SegmentTree(vector<Int> vec) {
        Int x = 1;
        while (x < (Int)vec.size()) {
            x *= 2;
        }
        this->N = x;
        data = vector<Int>(2 * x, DEFAULT_VALUE);
        for (int i = 0; i < (Int)vec.size(); i++) {
            update(i, vec[i]);
        }
    }

    Int get(Int l, Int r) {
        return getSub(l, r, 0, N, 1);
    }

    void update(Int index, Int val) {
        Int v = index + N;
        data[v] += val;

        v /= 2;
        while (v > 0) {
            data[v] = func(data[2 * v], data[2 * v + 1]);
            v /= 2;
        }
    }

    Int getSub(Int l, Int r, Int myl, Int myr, Int v) {
        if (myr <= l || r <= myl) return DEFAULT_VALUE;
        if (l <= myl && myr <= r) return data[v];

        Int mid = (myl + myr) / 2;
        return func(getSub(l, r, myl, mid, 2 * v),
                   getSub(l, r, mid, myr, 2 * v + 1));
    }
};
//////////////////////////////////////////////////

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree seg(vector<long long>(n, 0));
    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            seg.update(x - 1, y);
        } else {
            cout << seg.get(x - 1, y) << endl;
        }
    }
    return 0;
}