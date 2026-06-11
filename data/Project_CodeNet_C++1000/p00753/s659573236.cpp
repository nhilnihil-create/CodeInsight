#include<stdio.h>
#define MAX_N 123456
int prime[MAX_N*2];//index+1????´???°??????0?´???°??§????????????1
main(){
    //?´???°????±???????
    prime[0] = 1;
    for(int i = 2;i*i <= MAX_N*2;i++){
        for(int j = i*2;j <= MAX_N*2;j+=i){
            prime[j-1] = 1;
        }
    }
    int N;
    scanf("%d",&N);
    while(N){
        int count = 0;
        for(int i = N+1;i <= N*2;i++){
            count += !prime[i-1];
        }
        printf("%d\n",count);
        scanf("%d",&N);
    }
}