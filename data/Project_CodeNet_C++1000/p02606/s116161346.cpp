#include <stdio.h>

int main(){

    int num1,num2,n;
    int ctr = 0;
    scanf("%d %d %d", &num1, &num2, &n);

    for( int i = num1; i <= num2; i++){
        if(i % n == 0){
            ctr++;
        }
    }
    printf("%d", ctr);


    return 0;
}