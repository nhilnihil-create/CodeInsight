#include<atcoder/all>
using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    dsu G(N);

    rep(q, Q) {
        int c; scanf("%d", &c);
        if (c == 0) {
            int u, v; scanf("%d%d", &u, &v);
            G.merge(u, v);
        }
        if (c == 1) {
            int u, v; scanf("%d%d", &u, &v);
            printf(G.same(u, v) ? "1\n" : "0\n");
        }
    }

    return 0;
}