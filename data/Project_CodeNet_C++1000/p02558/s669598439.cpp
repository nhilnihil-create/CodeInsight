#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/dsu>

using ll = long long;

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    atcoder::dsu d(n);
    for (int i=0, t, u, v; i<q; i++) {
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << d.same(u, v) << '\n';
        }
    }
    return 0;
}