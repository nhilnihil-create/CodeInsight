#include <stdio.h>

int main()
{
    int s = 0;
    scanf("%d", &s);
    if((0 <= s) && (s < 86400))
    {
        printf("%d:%d:%d\n", s/3600, (s%3600)/60, s%60);
    }
    return 0;
}