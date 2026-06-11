#include <bits/stdc++.h>

using namespace std;

int a[200005];
double ps[200005];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        ps[i] = (1.0 * a[i] + 1.0) / 2;
        ps[i] += ps[i - 1];
    }

    double res = 0;
    for (int i = k; i <= n; i++) res = max(res, ps[i] - ps[i - k]);

    printf("%.12lf\n", res);
}
