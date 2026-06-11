#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main(void) {
    int N, Q;
    cin >> N >> Q;

    dsu uf(N);

    while(Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }
    return 0;
}
