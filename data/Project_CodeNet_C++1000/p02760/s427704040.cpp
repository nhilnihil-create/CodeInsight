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
    int bingo[3][3];
    rep(i, 3) rep(j, 3) {
        cin >> bingo[i][j];
    }
    int n, b;
    scanInt(n);
    rep(step, n) {
        scanInt(b);
        rep(i, 3) rep(j, 3) {
            if (bingo[i][j] == b) {
                bingo[i][j] = 0;
                break;
            }
        }
    }
    if (!bingo[0][0] && !bingo[0][1] && !bingo[0][2] ||
        !bingo[1][0] && !bingo[1][1] && !bingo[1][2] ||
        !bingo[2][0] && !bingo[2][1] && !bingo[2][2] ||
        !bingo[0][0] && !bingo[1][0] && !bingo[2][0] ||
        !bingo[0][1] && !bingo[1][1] && !bingo[2][1] ||
        !bingo[0][2] && !bingo[1][2] && !bingo[2][2] ||
        !bingo[0][0] && !bingo[1][1] && !bingo[2][2] ||
        !bingo[0][2] && !bingo[1][1] && !bingo[2][0]) {
        printYes();
    } else printNo();
    return 0;
}
