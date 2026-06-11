#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
using namespace std;

int main() {
    char s[11], t[11], u[11];
    int a, b;
    scanf("%s %s", s, t);
    scan2Int(a,b);
    scanf("%s", u);
    if (!strcmp(s, u))
        a -= 1;
    else
        b -= 1;

    printf("%d %d\n", a, b);
    return 0;
}
