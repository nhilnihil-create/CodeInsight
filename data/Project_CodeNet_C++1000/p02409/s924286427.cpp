
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int n, b, f, r, v, i, j, k;
    int list[4][3][10] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        getchar();
        scanf("%d%d%d%d", &b, &f, &r, &v);
        list[b-1][f-1][r-1] += v;
    }

    for (i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                printf("%2d", list[i][j][k]);
            }
            printf("\n");
        }
        if (i < 3)
        {
            printf("####################\n");
        }
    }
    return 0;
}