#include <atcoder/dsu>
#include <cstdio>

using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u;
        scanf("%d %d", &t, &u);
        d.merge(t-1, u-1);
    }
    printf("%d",d.groups().size()-1);
    return 0;
}
