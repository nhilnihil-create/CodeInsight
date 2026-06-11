#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define printYes() printf("Yes\n")
#define printNo() printf("No\n")
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4Int(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
typedef long long ll;
const int INF = 1001001001;
using namespace std;
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int gdc(int a, int b) {
    int r;
    if (a < b)
        swap(&a, &b);
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int k;
    ll total = 0;
    scanInt(k);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1; l <= k; ++l) {
               total += gdc(gdc(i, j), l);
    }}}
    printll(total);
    return 0;
}