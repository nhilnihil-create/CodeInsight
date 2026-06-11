#include <bits/stdc++.h>

using namespace std;
typedef long long llint;

const int maxn = 1e5+10;
const llint inf = 1e9+10;

int n;
llint m;
llint a[maxn];
int cnt[maxn];

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        a[i] /= 2;
    }

    for (int i = 0; i < n; i++) {
        llint tren = a[i];
        while (tren % 2 == 0) cnt[i]++, tren /= 2;
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (cnt[i] != cnt[i - 1]) flag = false;
    }

    if (!flag) {
        printf("0\n");
        return 0;
    }

    llint lc = a[0];
    for (int i = 0; i < n; i++) {
        lc = min(inf, lc * a[i] / __gcd(lc, a[i]));
    }

    llint x = m / lc;
    printf("%lld", (x + 1) / 2);
    return 0;
}
