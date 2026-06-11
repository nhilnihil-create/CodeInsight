#include <stdio.h>

int main(){
    int l;
    int r;
    int d;
    int a=0;
    scanf("%d %d %d", &l,&r,&d);

    for (int i =l; i <= r; i++){
        if(i%d==0){
        a = a+1;
        }
    }
    printf("%d", a);
    return 0;
}