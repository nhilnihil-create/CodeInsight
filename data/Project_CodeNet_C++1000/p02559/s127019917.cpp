#include <bits/stdc++.h>
#include "atcoder/dsu"
#include "atcoder/fenwicktree"
typedef long long int ll;
using namespace std;
using namespace atcoder;
int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> f(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        f.add(i, a);
    }
    vector<ll> ans;
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            f.add(y, z);
        }
        else {
            ans.push_back(f.sum(y, z));
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}