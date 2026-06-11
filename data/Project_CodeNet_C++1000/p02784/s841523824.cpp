#include<stdio.h>

int main()
{
    int H, N, i, sum=0;

    scanf("%d %d", &H, &N);

    int A[N+2];

    for(i=1; i<=N; i++){///0.001+0.001
        scanf("%d", &A[i]);
    }

    for(i=1; i<=N; i++){
        sum += A[i];
        if(sum >= H){
            N=0;
            break;
        }

    }

    if(N==0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
