#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    n *= (n - 1);
    n /= 2;
    m *= (m - 1);
    m /= 2;
    printf("%d", n + m);
}