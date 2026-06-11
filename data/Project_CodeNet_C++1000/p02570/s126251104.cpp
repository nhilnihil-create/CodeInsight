#include <stdio.h>

int main()
{
    int D, T, S;
    int mani;

    scanf("%d%d%d", &D,&T,&S);
    mani = T * S;
    if (D <= mani)
        printf("Yes");
    else
        printf("No");
    return 0;

}