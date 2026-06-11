#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4Int(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
typedef long long ll;
using namespace std;

int main() {
    int thp, tatk, ahp, aatk;
    scan4Int(thp, tatk, ahp, aatk);
    bool flag = false;
    while(thp > 0 && ahp > 0) {
        flag = !flag;
        if (flag) {
            ahp -= tatk;
        } else {
            thp -= aatk;
        }
    }
    if (thp <= 0) 
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
