#include <cstdio>

int main () {
    int H, W;
    for (int i = 0;;i++) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) break;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}