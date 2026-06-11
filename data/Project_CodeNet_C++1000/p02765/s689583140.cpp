#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
using namespace std;

int main() {
    int n, r, ans;
    scan2Int(n, r);    
    if (n >= 10) ans = r;
    else ans = r + 100 * (10 - n);
    printInt(ans);
    return 0;
}
