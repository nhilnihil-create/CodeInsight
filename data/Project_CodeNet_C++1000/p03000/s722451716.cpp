#include<stdio.h>

int main()
{
    int N, X, D1 = 0, D2=1, L;

    scanf("%d %d", &N, &X);

    for(int i=1; i<=N; i++)
    {
        scanf("%d", &L);

        D1 = D1 + L;

        if(D1 <= X)D2++;
    }

    printf("%d", D2);

    return 0;

}