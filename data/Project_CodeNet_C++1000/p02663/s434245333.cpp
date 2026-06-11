#include <stdio.h>

int main() {
    int h1, m1, h2, m2, k;
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
    h1 *= 60;
    h2 *= 60;
    h1 += m1;
    h2 += m2;
    int diff = h2 - h1;
    if (k == h2) {
        printf("0");
        return 0;
    }
    printf("%d", diff - k);
}