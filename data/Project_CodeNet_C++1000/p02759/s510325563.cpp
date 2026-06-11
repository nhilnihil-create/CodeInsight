#include<stdio.h>

int main()
{
    int N, paper = 0;
    scanf("%d", &N);
    while (N > 0)
    {
        paper++;
        N -= 2;
    }
    printf("%d", paper);

    return 0;
}