#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printInt(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define scanll(a) scanf("%lld", &a)
#define scanInt(a) scanf("%d", &a)
#define scan2Int(a, b) scanf("%d %d", &a, &b)
#define scan3Int(a, b, c) scanf("%d %d %d", &a, &b, &c)
typedef long long ll;
using namespace std;

int main() {
    ll x, deposite = 100;
    scanll(x);
    int count = 0;
    while (deposite < x) {
        deposite += deposite / 100;
        count++;
    }
    printInt(count);
    return 0;
}
