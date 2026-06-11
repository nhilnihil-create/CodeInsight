#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main(void) {
    int N, Q;
    cin >> N >> Q;

    fenwick_tree<int64_t> fen(N);
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        fen.add(i, a);
    }

    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, x;
            cin >> p >> x;
            fen.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fen.sum(l, r) << endl;
        }
    }
    return 0;
}
