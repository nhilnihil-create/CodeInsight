#include <stdio.h>

int main(void)
{
    int H, W;
    
    while (1) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) break;
        else {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (j == W - 1) printf("#\n");
                    else printf("#");
                }
            }
        }
        printf("\n");
    }
    return 0;
}