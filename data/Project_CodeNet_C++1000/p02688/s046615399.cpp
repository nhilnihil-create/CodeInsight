#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
typedef long long ll;
using namespace std;

int main() {
    int n, k, d, a;
    scan2Int(n, k);
    bool men[n];
    rep(i, n) men[i] = false;
    rep(step, k) {
        scanInt(d);
        rep(i, d) {
            scanInt(a);
            a -= 1;
            men[a] = true;
        }
    }
    int count = 0;
    rep(i, n) {
        if (!men[i]) count++;
    }
    printInt(count);
    return 0;
}
