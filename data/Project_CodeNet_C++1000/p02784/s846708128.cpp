#include<stdio.h>
int main(){
    int H,N,i,A,sum;
    sum=0;
    scanf("%d%d",&H,&N);
    for(i=1;i<=N;i++){
        scanf("%d",&A);
        sum=sum+A;
    }
    if(sum>=H)
    printf("Yes");
    else
    printf("No");
  
    return 0;
}