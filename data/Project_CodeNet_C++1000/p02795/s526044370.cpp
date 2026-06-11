#include <stdio.h>

int main() {
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    h > w ? printf("%d\n", (n + h - 1) / h) : printf("%d\n", (n + w - 1) / w);
}
