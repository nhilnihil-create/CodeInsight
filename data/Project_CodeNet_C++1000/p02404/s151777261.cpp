#include <stdio.h>

int main(void)
{
    int h, w, i, j;

    scanf("%d %d", &h, &w);

    while((h != 0) && (w != 0)) {
        for (i=0; i<w;i++)
            printf("#");
        printf("\n");
        for (i=0; i < h-2; i++) {
            printf("#");
            for (j=0; j<w-2; j++) {
                printf(".");
            }
            printf("#");
            printf("\n");
        }
        for (i=0; i<w;i++)
            printf("#");
        printf("\n");

        scanf("%d %d", &h, &w);
        printf("\n");
    }

    return 0;
}