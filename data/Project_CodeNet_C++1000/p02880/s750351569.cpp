#include<stdio.h>

int main(){
    int a,x=0;
    scanf("%d", &a);
    for(int i=1; i<=9 ; i++){
        if(a%i==0){
            if(a/i>=1 && a/i<=9){
                x=1;
                break;
            }
        }
    }
    if (x==1)
    printf("Yes\n");
    else
    printf("No\n");;
    return 0;
}