#include <stdio.h>

int main() {
    int h, w, n, ops = 0, c = 0;
    scanf("%d", &h);
    scanf("%d", &w);
    scanf("%d", &n);
    while (n > ops) {
        if (w > h) {
            ops += w;
            c++;
        } else {
            ops += h;
            c++;
        }
    }
    printf("%d", c);
}