#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
	int n, q;
    cin >> n >> q;
    dsu uf(n);
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t) {
            cout << int(uf.same(u, v)) << endl;
        } else {
            uf.merge(u, v);
        }
    }
}
