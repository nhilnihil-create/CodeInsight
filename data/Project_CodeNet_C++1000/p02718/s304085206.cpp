#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4Int(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
typedef long long ll;
using namespace std;

int main() {
    int n, m, total = 0;
    scan2Int(n, m);
    int as[n];
    rep(i, n) {
        cin >> as[i];
        total += as[i];
    }
    double border = (double) total / (4 * m);
    rep(i, n) {
        if (as[i] >= border)
            m -= 1;
        if (m <= 0) break;
    }
    if (m <= 0)
        printf("Yes\n");
    else 
        printf("No\n");
    return 0;
}
