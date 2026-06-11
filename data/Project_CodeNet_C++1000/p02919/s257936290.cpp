#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>


class SegmentTree {
private:
    using Monoid = int;
    const Monoid INI = -1;
    Monoid op(Monoid a, Monoid b) const {
        return std::max(a, b);
    }

    int num;
    std::vector<Monoid> dat;

public:
    SegmentTree(int n_) {
        num = 1;
        while (num < n_) num *= 2;
        dat.resize(2 * num, INI);
    }

    SegmentTree(const std::vector<Monoid> &m) : SegmentTree(m.size()) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // Update the k-th value (0-indexed) to a.
    void update(int k, Monoid a) {
        k += num - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) const {
        if (right < 0) right = num;
        if (right <= a || b <= left) return INI;
        if (a <= left && right <= b) return dat[k];
        Monoid vleft = getval(a, b, 2 * k + 1, left, left + (right - left) / 2);
        Monoid vright = getval(a, b, 2 * k + 2, left + (right - left) / 2, right);
        return op(vleft, vright);
    }
};


int binsearch_left(int lo, int hi, int right, int targ, const SegmentTree &seg) {
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        int val = seg.getval(mid, right);
        if (val > targ) lo = mid;
        else hi = mid;
    }
    return hi;
}


int binsearch_right(int lo, int hi, int left, int targ, const SegmentTree &seg) {
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        int val = seg.getval(left, mid + 1);
        if (val > targ) hi = mid;
        else lo = mid;
    }
    return lo;
}


int main() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    a[n] = 1e9;
    SegmentTree seg(a);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l0 = binsearch_left(-1, i, i, a[i], seg);
        if (l0 > 0) seg.update(l0 - 1, -1);
        int l1 = binsearch_left(-1, i, i, a[i], seg);
        if (l0 > 0) seg.update(l0 - 1, a[l0 - 1]);

        int r0 = binsearch_right(i, n + 1, i, a[i], seg);
        if (r0 < n - 1) seg.update(r0 + 1, -1);
        int r1 = binsearch_right(i, n + 1, i, a[i], seg);
        if (r0 < n - 1) seg.update(r0 + 1, a[r0 + 1]);
        
        l0 = std::abs(l0 - i);
        l1 = std::abs(l1 - i);
        r0 = std::abs(r0 - i);
        r1 = std::abs(r1 - i);
        ans += (long long)(l0 + 1)*(r1 - r0)*a[i];
        ans += (long long)(r0 + 1)*(l1 - l0)*a[i];
    }
    std::cout << ans << std::endl;
    return 0;
}
