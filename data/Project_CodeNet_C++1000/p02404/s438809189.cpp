#include <cstdio>

int main(void)
{
    while (1) {
        int h, w;
        scanf("%d %d", &h, &w);
        if (!h && !w)
            break;

        for (int y=1; y<=h; y++) {
            for (int x=1; x<=w; x++) {
                if (((x>1)&&(x<w)) && ((y>1)&&(y<h)))
                    printf(".");
                else
                    printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}