#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main () {
    int n,Q;
    cin >> n >> Q;
    dsu d(n);
    while(Q--) {
        int type,u,v;
        cin >> type >> u >> v;
        if(type == 0) d.merge(u,v);
        if(type == 1) cout << d.same(u,v) << endl;
    }
    return 0;
}
