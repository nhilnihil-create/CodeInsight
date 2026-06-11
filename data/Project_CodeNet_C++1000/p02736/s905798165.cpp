#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;
int a[nax], b[nax];
int c[3];
int ncr[2][2];

int lucas (int n, int r) {
    if (r > n) return 0;
    int ret = 1;
    while (n > 0 || r > 0) {
        int x = n % 2;
        int y = r % 2;
        n >>= 1 ;
        r >>= 1;
        ret *= (ncr[x][y]);
        ret %= 2;
    }
    return ret;
}
int n;


int main () {
    ncr[0][0] = ncr[1][0] = ncr[1][1] = 1;
    scanf("%d", &n);

    for (int i = 0 ; i < n ; ++ i) {
        scanf("%1d", &a[i]);
        b[i] = a[i];
    }

    int p = 0;
    for (int i = 0 ; i < n; ++ i) {
        int t = (a[i] % 2) * lucas(n - 1, i);
        p += t;
        p %= 2;
    }

    if (p & 1) return !printf("1");

    for (int i = 0 ; i < n - 1; ++ i) {
        a[i] = abs(b[i + 1] - b[i]);
        c[a[i]] ++;
    }
    -- n;

    if (c[1] > 0) {
        return !printf("0");
    }

    for (int i = 0 ; i < n;  ++ i) {
        a[i] >>= 1;
    }
    p = 0;
    for (int i = 0 ; i < n; ++ i) {
        int t = (a[i] % 2) * lucas(n - 1, i);
        p += t;
        p %= 2;
    }

    printf("%d\n", (p & 1) * 2);

}
