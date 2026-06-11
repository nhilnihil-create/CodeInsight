#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
using namespace std;

int main() {
    int k, a, b;
    scanInt(k);
    scan2Int(a, b);
    if (a%k == 0) {
        printf("OK\n");
        return 0;
    }
    int tmp = k - a % k;
    if (tmp <= b-a) printf("OK\n");
    else printf("NG\n");
    return 0;
}
