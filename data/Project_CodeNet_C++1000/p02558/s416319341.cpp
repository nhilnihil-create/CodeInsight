#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int n, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    dsu d(n);
    while (q--) {
        int tp, u, v;
        scanf("%d%d%d", &tp, &u, &v);
        if (!tp) {
            d.merge(u, v);
        } else {
            printf("%d\n", d.same(u, v));
        }
    }
    return 0;
}
