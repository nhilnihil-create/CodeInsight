#include <stdio.h>

int main()
{
    int H, W;

    while (scanf("%d%d", &H, &W) == 2 && !(H == 0 && W == 0)) {
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++)
                putchar('#');
            putchar('\n');
        }
        putchar('\n');
    }
}