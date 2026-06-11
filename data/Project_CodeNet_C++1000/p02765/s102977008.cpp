#include <stdio.h>

int main()
{
    int N,R,disp;
    scanf("%d%d", &N, &R);

    if (N >= 10)
    {
        disp = R;
    }
    else 
    {
        disp = R + (100 * (10-N));
    }
    printf("%d", disp);
    return 0;
}