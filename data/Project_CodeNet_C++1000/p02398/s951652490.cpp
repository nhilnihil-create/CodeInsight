#include <stdio.h>

int main(void)
{
    int a, b, c, count;
    count = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (c < a) {
        printf("%d\n", 0);
        return 0;
    }

    if (a == b) {
        printf("%d\n", 1);
        return 0;
    }

    while (a <= b) {
        if ((c % a) == 0)
            count = count + 1;
        a = a + 1;
    }
    
    printf("%d\n", count);

    return 0;
}