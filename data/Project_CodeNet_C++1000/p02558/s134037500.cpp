#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        if (t == 0) {
            d.merge(u, v);
        } else {
            if (d.same(u, v)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}