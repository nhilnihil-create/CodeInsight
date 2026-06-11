#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    int N, Q;
    cin >> N >> Q;

    dsu uf(N);
    for_(i,0,Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.merge(u, v);
        else puts(uf.same(u, v) ? "1" : "0");
    }
}