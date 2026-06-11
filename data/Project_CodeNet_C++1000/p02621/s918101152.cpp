#include <stdio.h>

int main (){
    int a;
    scanf("%d", &a);
    int pangkat;
    int sum=0;

    for(int i =0; i <= a; i++){
    pangkat = a * a;
    sum = sum + pangkat;
    }
    printf("%d\n", sum+a);
    return 0;
}