#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/fenwicktree>

using ll = long long;

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    atcoder::fenwick_tree<ll> fwt(n);
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        fwt.add(i, ai);
    }
    for (int i=0, t, a, b; i<q; i++) {
        cin >> t >> a >> b;
        if (t == 0) {
            fwt.add(a, b);
        } else {
            cout << fwt.sum(a, b) << '\n';
        }
    }
    return 0;
}