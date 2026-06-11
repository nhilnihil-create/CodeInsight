#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int n, q; cin >> n >> q;
    fenwick_tree<long long> data(n);
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        data.add(i,a);
    }
    while (q--) {
        int t; cin >> t;
        if (t) {
            int l, r; cin >> l >> r;
            cout << data.sum(l,r) << "\n";
        }
        else {
            int p; long long x; cin >> p >> x;
            data.add(p,x);
        }
    }
    return 0;
}