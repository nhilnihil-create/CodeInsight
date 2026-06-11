#include <stdio.h>


int main(){
    int a;
    scanf("%d", &a);

    int sum = a;
    int temp = a;
    for (int i=0; i<2; i++){
        temp *= a;
        sum += temp;
    }

    printf("%d\n", sum);


    return 0;
}