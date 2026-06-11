#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

ll N, Q, a, q, p, x, l, r;

int main() {
    scanf("%lld%lld", &N, &Q);
    fenwick_tree<ll> fw(N);
    rep(i, N) {
        scanf("%lld", &a);
        fw.add(i, a);
    }
    rep(i, Q) {
        scanf("%lld", &q);
        if (q == 0) {
            scanf("%lld%lld", &p, &x);
            fw.add(p, x);
        } else {
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", fw.sum(l, r));
        }
    }
}