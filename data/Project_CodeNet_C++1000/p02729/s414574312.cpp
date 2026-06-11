#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    N = ((N*N)/2) - (N/2);
    M = ((M*M)/2) - (M/2);
    
    printf("%d", N+M);

    return 0;
}
