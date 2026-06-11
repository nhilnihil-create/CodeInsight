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
 
int main() {
    char s[101], t[101];
    rep(i, 101) s[i] = t[i] = '\0';
    scanf("%s", s);
    scanf("%s", t);
    int p = 0;
    while (t[p] != '\0') {
        printf("%c", t[p++]);
    }
    p = 0;
    while (s[p] != '\0') {
        printf("%c", s[p++]);
    }
    printf("\n");
    return 0;
}