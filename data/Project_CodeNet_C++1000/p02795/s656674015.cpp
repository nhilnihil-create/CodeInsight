#include <stdio.h>

int max(int a, int b) {
    if (a>=b) return a;
    else return b;
}

int main() {
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    int hi=max(h, w);
    n+=hi-1;
    printf("%d\n", n/hi);
}
