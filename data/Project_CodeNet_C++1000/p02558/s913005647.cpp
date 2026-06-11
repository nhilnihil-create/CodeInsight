#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int a = int(5);
    int n, q;
    cin >> n >> q;
    dsu d(n);
    for (ll i = 0;i < q;++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        }
        else if (t == 1) {
            cout << d.same(u, v) << endl;
        }
        else cout << "WA";
    }
}
