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
using namespace std;

int main() {
    char s[100];
    rep(i, 100) s[i] = '\0';
    scanf("%s", s);
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    int sublen = (count - 1) / 2;
    char a[sublen], b[sublen];
    rep(i, sublen) {
        a[i] = s[i];
        b[i] = s[count - 1 - i];
    }
    rep(i, sublen) {
        if (a[i] != b[i]) {
            printNo();
            return 0;
        }
    }
    rep(i, sublen/ 2) {
        if (a[i] != a[sublen- 1 - i] ||
            b[i] != b[sublen -1 - i]) {
            printNo();
            return 0;
        }
    }
    printYes();
    return 0;
}
