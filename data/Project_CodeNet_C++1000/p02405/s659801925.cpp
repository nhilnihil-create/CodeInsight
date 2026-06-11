#include <stdio.h>

int main(void)
{
    int H, W;
    
    while (1) {
        scanf("%d %d", &H, &W);
        
        if (H == 0 && W == 0) {
            break;
        } else {
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0)) printf(".");
                    else printf("#");
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}