#include <stdio.h>

int main()
{
    int h1, m1, h2, m2, k;
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);

    int period = ((h2 * 60) + m2) - ((h1 * 60) + m1) - k;
    printf("%d\n", period);
    return 0;
}