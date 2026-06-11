#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++) {
        ll a;
        scanf("%lld", &a);
        fw.add(i, a);
    }
    for (int z = 0; z < Q; z++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p;
            ll x;
            scanf("%d %lld", &p, &x);
            fw.add(p, x);
        }else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", fw.sum(l, r));
        }
    }
}