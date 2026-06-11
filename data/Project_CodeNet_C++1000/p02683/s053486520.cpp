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
    int n,m,x;
    scan3Int(n,m,x);
    int books[n][m];
    int costs[n];
    rep(i, n) {
        cin >> costs[i];
        rep(j, m) {
            cin >> books[i][j];
        }
    }
    int counts[m], min = INF, total;
    bool flag;
    rep(bits, 1 << n) {
        flag = true;
        total = 0;
        rep(i, m) counts[i] = 0;
        rep(i, n) {
            if (bits >> i & 0b1) {
                total += costs[i];
                rep(j, m) {
                    counts[j] += books[i][j]; 
                }
            }
        }
        rep(i, m) if (counts[i] < x) flag = false;
        if (flag) 
            min = min < total ? min : total;
    }
    if (min == INF) printInt(-1);
    else printInt(min);
    return 0;
}