#include<atcoder/all>
using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL RSQ_e() { return 0; }
LL RSQ_up(LL a, LL b) { return a + b; }
using RSQ = segtree<LL, RSQ_up, RSQ_e>;

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<LL> A(N); rep(i, N) { int a; scanf("%d", &a); A[i] = a; }
    RSQ G(A);

    rep(q, Q) {
        int c; scanf("%d", &c);
        if (c == 0) {
            int p, x; scanf("%d%d", &p, &x);
            G.set(p, G.get(p) + x);
        }
        if (c == 1) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%lld\n", G.prod(l,r));
        }
    }

    return 0;
}