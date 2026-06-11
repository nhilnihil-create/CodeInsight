#include<stdio.h>
int main()
{
    int H, N, i, x ,sum = 0;

    scanf("%d %d", &H, &N);

    for (i = 0 ; i < N ; i++)
    {
        scanf("%d", &x);
        sum += x;
    }

    if(sum >= H)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

