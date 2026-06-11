#include <iostream>

int main(){
    int a,b;
    int sum = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    if(a == 3){
        sum += 100000;
    } else if(a == 2){
        sum += 200000;
    }else if(a == 1){
        sum += 300000;
    }

    if(b == 3){
        sum += 100000;
    } else if(b == 2){
        sum += 200000;
    }else if(b == 1){
        sum += 300000;
    }

    if(b == 1 && a==1){
        sum += 400000;
    }

    printf("%d\n",sum);
    return 0;
}