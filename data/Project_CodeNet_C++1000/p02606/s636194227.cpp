#include <stdio.h>

int main()
{
    int L, R, d;

    scanf("%d%d%d", &L, &R, &d);

    int num = 0;
    for (int i = L; i <= R; i++)
    {
        if (i % d == 0)
        {
            num++;
        }
    }

    printf("%d\n", num);

    return 0;
}