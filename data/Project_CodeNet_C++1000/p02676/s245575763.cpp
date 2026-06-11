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
    int k;
    char s[101];
    scanInt(k);
    rep(i, 101) s[i] = '\0';
    scanf("%s", s);
    for (int i = 0; i < k && s[i] != '\0'; ++i)
        printf("%c", s[i]);
    if (s[k] != '\0') {
        printf("...");
    }
    printf("\n");
    return 0;
}
