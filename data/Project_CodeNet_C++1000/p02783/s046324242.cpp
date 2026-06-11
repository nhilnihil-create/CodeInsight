#include <stdio.h>

int main ()
{
    int h, a;
    scanf("%d%d", &h, &a);
    int yuh =h/a;
    h%a ==0? yuh : ++yuh;
    printf("%d\n", yuh);
    return 0;
}
