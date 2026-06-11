#include <iostream>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main() {
    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        }
        else {
            if (d.same(u, v)) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }
    return 0;
}