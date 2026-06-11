#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;


int main(void) {
    int n, q, a, t, tmp1, tmp2;

    cin >> n >> q;
    fenwick_tree<long> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        tree.add(i, a);
    }

    for (int i = 0; i < q; ++i) {
        cin >> t >> tmp1 >> tmp2;
        switch (t) {
            case 0:
                tree.add(tmp1, tmp2);
                break;
            case 1:
                cout << tree.sum(tmp1, tmp2) << endl;
                break;
            default:
                ;
        }
    }

    return 0;
}
