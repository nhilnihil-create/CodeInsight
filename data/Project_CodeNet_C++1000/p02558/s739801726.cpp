#include <bits/stdc++.h>
#include "atcoder/dsu"
typedef long long int ll;
using namespace std;
using namespace atcoder;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> ans;
    dsu d(n);
    for (int i = 1; i <= q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        }
        else {
            if (d.same(u, v)) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}