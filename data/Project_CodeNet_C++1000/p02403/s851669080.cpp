#include <iostream>
int main() {
    int h,w;
    while (scanf("%d %d", &h, &w)) {
        if (h == 0 && w == 0) break;
        for (int i = 0; i++ < h;) {
            for (int j = 0; j++ < w;) printf("%c", '#');
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}