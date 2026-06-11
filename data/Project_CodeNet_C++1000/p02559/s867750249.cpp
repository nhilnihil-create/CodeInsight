#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
using namespace atcoder;

int main () {
    int n,Q;
    cin >> n >> Q;

    fenwick_tree<ll> fw(n);
    rep(i,n) {
        int a; cin >> a;
        fw.add(i,a);
    }

    while(Q--) {
        int type;
        cin >> type;
        if(type == 0) {
            int p,x;
            cin >> p >> x;
            fw.add(p,x);
        }
        if(type == 1) {
            int l,r;
            cin >> l >> r;
            cout << fw.sum(l,r) << endl;
        }
    }
    return 0;
}
