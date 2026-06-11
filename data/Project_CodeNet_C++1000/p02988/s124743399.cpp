#include<stdio.h>

int main()
{
    int n, i, count=0;

    scanf("%d", &n);

    int P[n+1];

    for(i=1; i<=n; i++){
        scanf("%d", &P[i]);
    }

    for(i=2; i<n; i++){
        if((P[i-1]<=P[i] && P[i]<P[i+1]) || (P[i-1]>P[i] && P[i]>=P[i+1]))
            count++;
    }

    printf("%d\n", count);

    return 0;
}
