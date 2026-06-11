#include<stdio.h>

int main()
{
    int N, i, j, test;
    unsigned long long mul;
    long long A[100001], tt=1000000000000000000;

    scanf("%d", &N);


    mul=1;
    test=1;
    for(i=1; i<=N; i++){
        scanf("%lld", &A[i]);
    }
    for(i=1; i<=N; i++){
        if(A[i]==0){
            test=0;
            break;
        }

        if(tt/mul >= A[i])
        {
            mul *= A[i];
        }
        else
            test=2;


    }

        if(test==0)
            printf("0\n");
        else if(test==1)
            printf("%llu\n", mul);
        else if(test==2)
            printf("-1\n");

    return 0;
}
