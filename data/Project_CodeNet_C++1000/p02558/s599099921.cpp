#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

#include <atcoder/dsu>

using namespace std;
using namespace atcoder;
#define rep(i,l,r) for(int i = l; i < r; i++)

int main() {
    int n, q;
    cin >> n >> q;

    dsu d(n);

    rep(i, 0, q) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << (d.same(u, v)) << endl;
        }
    }
}
