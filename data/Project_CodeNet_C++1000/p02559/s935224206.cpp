#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
#define rep(i,l,r) for(int i = l; i < r; ++i)

int main() {
    int n, q, a;
    cin >> n >> q;

    fenwick_tree<unsigned long long> ft(n);
    rep(i, 0, n) {
        cin >> a;
        ft.add(i, a);
    }

    rep(i, 0, q) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 0) {
            ft.add(x, y);
        } else {
            cout << ft.sum(x, y) << endl;
        }
    }
}
