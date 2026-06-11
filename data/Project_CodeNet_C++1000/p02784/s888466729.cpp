#include<stdio.h>

int main()
{
    int H, N, sum = 0;

    scanf("%d %d", &H, &N);

    int A[N];

    for(int i=0; i<N; i++)
    {
        scanf("%d", &A[i]);

        sum += A[i];
    }

    if(sum>=H)printf("Yes");

    else printf("No");

    return 0;
}