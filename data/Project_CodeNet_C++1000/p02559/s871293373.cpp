#include <atcoder/fenwicktree>
#include <cstdio>
 
using namespace std;
using namespace atcoder;
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    fenwick_tree<long> t = fenwick_tree<long>(n);
    for (int i = 0; i < n; ++i) {
        long a;
        scanf("%ld", &a);
        t.add(i, a);
    }

    int f;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &f);
        if (f == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%ld\n", t.sum(l, r));
        } else {
            int p;
            long x;
            scanf("%d %ld", &p, &x);
            t.add(p, x);
        }
    }
 
    return 0;
}
