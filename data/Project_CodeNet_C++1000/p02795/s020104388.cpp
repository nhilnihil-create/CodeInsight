#include <stdio.h>

int main() {
    int h, w, n;
    // 3 7
    scanf("%d %d %d", &h, &w, &n);
    if (h > w) {
        int swap = h;
        h = w;
        w = swap;
    }
    n % w == 0 ? printf("%d\n", n / w) : printf("%d\n", n / w + 1);
}
