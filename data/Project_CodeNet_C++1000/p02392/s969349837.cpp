#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c)
        printf("Yes\n", a, b, c);
    else if (a >= b || a >= c || b >= c)
        printf("No\n", a, b, c);

    return 0;
}
