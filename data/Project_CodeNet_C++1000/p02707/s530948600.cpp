#include <stdio.h>
int a[200010];
int main() {
    int n, i, x;
    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for (i = 1; i <= n; i++) printf("%d\n", a[i]);
    return 0;
}
