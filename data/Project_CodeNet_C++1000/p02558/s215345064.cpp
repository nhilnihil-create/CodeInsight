#include <atcoder/dsu>
#include <cstdio>
 
using namespace std;
using namespace atcoder;
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
 
    dsu d = dsu(n);
    int t, u, v;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &t, &u, &v);
        if (t == 1) {
            printf("%d\n", d.same(u, v));
        } else {
            d.merge(u, v);
        }
    }
 
    return 0;
}
