#include <cstdio>

int main(void)
{
    while (1) {
        int h, w;
        scanf("%d %d", &h, &w);
        if (!h && !w)
            break;

        for (int y=0; y<h; y++) {
            for (int x=0; x<w; x++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}