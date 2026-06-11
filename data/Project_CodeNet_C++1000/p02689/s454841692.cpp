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
    int n,m,a,b;
    scan2Int(n,m);
    int h[n];
    bool flags[n];
    rep(i, n) {
        cin >> h[i];
        flags[i] = true;
    }
    rep(i, m) {
        scan2Int(a,b);
        a -= 1; b -= 1;
        if (h[a] == h[b])
            flags[a] = flags[b] = false;
        else if (h[a] > h[b])
            flags[b] = false;
        else
            flags[a] = false;
    }
    int count = 0;
    rep(i, n) if (flags[i]) count++;
    printInt(count);
    return 0;
}