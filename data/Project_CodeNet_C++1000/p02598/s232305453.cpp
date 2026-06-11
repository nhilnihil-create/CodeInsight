#include <bits/stdc++.h>

using namespace std;

int n, k, a[200005];

long long check(int v) {
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += (a[i] - 1) / v;
    }

    return tot;
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int lb = 0;
    int ub = 1e9;

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;

        if (check(mid) <= k) ub = mid;
        else lb = mid;
    }

    printf("%d\n", ub);
}
