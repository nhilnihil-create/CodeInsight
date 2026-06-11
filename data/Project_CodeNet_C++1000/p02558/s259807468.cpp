#include <atcoder/dsu>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    cin >> n >> q;
    dsu d(n);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) d.merge(u, v);
        else if(d.same(u, v)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}