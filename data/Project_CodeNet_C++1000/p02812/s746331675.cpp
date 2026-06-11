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
    int n;
    scanInt(n);
    char s[n+1];
    scanf("%s", s);
    int count = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (i+2 < n &&
            s[i] == 'A' && 
            s[i+1] == 'B' && 
            s[i+2] == 'C')
            count++;
    }
    printInt(count);
    return 0;
}