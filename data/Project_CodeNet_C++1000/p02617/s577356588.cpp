#include <bits/stdc++.h>

using namespace std;

int n;
long long res = 0;

int main() {
    scanf("%d", &n);
    res = 1ll * n * (n + 1) * (n + 2) / 6ll;
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        res -= 1ll * x * (n - y + 1);
    }
    printf("%lld", res);
}
