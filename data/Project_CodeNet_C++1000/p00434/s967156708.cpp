#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>

int main() {
    bool st[30] = {false};
    int n;
    for (int i =0;i<28;++i) {
        scanf(" %d", &n);
        st[n-1] = true;
    }

    int r[2] = {0};
    int of = 0;
    for (int i=0; i < 30; ++i) {
        if (!st[i]) {
            r[of] = i;
            of++;
        }
    }

    if (r[1] < r[0]) {
        int t = r[0];
        r[0] = r[1];
        r[1] = t;
    }

    printf("%d\n%d\n", r[0] + 1, r[1] + 1);

    return 0;
}