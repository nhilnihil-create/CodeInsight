#include <stdio.h>

int main(){
    int N, R;
    scanf("%d %d", &N, &R);
    if(N<=10){
        printf("%d", (100*(10-N)+R));
    }else if(N>10){
        printf("%d", R);
    }
    return 0;
}