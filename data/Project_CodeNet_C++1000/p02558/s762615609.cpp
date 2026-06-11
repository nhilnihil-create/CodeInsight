#include <atcoder/convolution>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <atcoder/maxflow>
#include <atcoder/mincostflow>
#include <atcoder/modint>
#include <atcoder/scc>
#include <atcoder/segtree>
#include <atcoder/string>
#include <atcoder/twosat>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using namespace internal;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)

int main() {
    int n,q;
    cin >> n >> q;
    dsu uf(n);
    rep(i,q) {
        int t, u1, u2;
        cin >> t >> u1 >> u2;
        if(t == 0) {
            uf.merge(u1,u2);
        }else if(t == 1) {
            int ans = 0;
            if(uf.same(u1,u2)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}