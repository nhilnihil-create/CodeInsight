#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;

int n, k;
int a[maxn];

bool check(int mid) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        num += a[i] / mid + (a[i] % mid != 0) - 1;
        if (num > k) return false;
    }
    return true;
}

int main() {
    int l = 1, r, mid;
    r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        r = max(r, a[i]);
    }
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
