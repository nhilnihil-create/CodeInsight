#include<stdio.h>
int main()
{
    int A,B,max;
    int c=0;
    scanf("%d %d",&A ,&B);
    if(A>=B){
        max=A;
    }
    else{
        max=B;
    }
    for(int i=1;i<max;i++){
        if((A-i)==(B-i)||(i-A)==(i-B)||(i-A)==(B-i)||(A-i)==(i-B)){
                c=i;
                break;
        }
    }
    if(c==0){
        printf("IMPOSSIBLE\n");
    }
    else{
        printf("%d\n",c);
    }
}
