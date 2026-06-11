#include <stdio.h>

int main(void)
{
    int N;
    int min,max,ret;
    int i;
    scanf("%d",&N);

    // 探索範囲下限
    min = N / 1.1;
    for(i=min;i<=N;i++){
        if((int)(i*1.08) == N){
            printf("%d\n",i);
            return 0;
        }
    }
    printf(":(\n");
    return 0;
}
