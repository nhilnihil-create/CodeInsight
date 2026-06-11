#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;


int main() {
    int n,q; cin >> n >> q;
    dsu uf(n);
    rep(i,q) {
        int t,u,v; cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u,v);
        } else {
            if (uf.same(u,v)) printf("%d\n", (int)1);
            else printf("%d\n", (int)0);
        }
    }
    return 0;
}
