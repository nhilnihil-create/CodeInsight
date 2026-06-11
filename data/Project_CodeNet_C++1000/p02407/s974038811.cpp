
#include <stdio.h>

int main(void)
{
    int n, i;

    scanf("%d", &n);

    int list[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[n - 1 - i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d", list[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}