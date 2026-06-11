#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
using namespace std;

int main() {
    char s[11], t[12];
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != t[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
