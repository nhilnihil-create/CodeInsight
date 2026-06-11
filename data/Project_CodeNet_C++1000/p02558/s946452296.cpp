#include <atcoder/all>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
using namespace atcoder;
int main() {
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    for(int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t) {
            cout << uf.same(u, v) << endl;
        } else {
            uf.merge(u, v);
        }
    }
}