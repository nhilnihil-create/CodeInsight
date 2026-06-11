#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long res = 0;

    sort(a, a + n, greater<int>());

    for (int i = k; i < n; i++) res += a[i];

    printf("%lld\n", res);
}
