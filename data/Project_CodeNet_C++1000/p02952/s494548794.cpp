#include<stdio.h>

int main()
{
    int N, i, s=1, count=0;

    scanf("%d", &N);

    for(i=1; i<=N; i++){
        if(1*s <= i && i < 10*s){
            count++;
            if(i == (10*s-1))
                s *=100;
        }
    }

    printf("%d\n", count);

    return 0;
}
