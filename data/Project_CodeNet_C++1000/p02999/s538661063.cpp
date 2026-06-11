#include <stdio.h>
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a - b < 0){
        printf("0");
    }else{
        printf("10");
    }    
    return 0;
}
