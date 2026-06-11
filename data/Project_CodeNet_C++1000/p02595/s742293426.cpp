#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    scanf("%d%d", &n, &d);

    int res = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (1LL * x * x + 1LL * y * y <= 1LL * d * d) res++;
    }

    printf("%d\n", res);
}
