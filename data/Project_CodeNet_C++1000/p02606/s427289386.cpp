#include <stdio.h>

int main(){
    int L, R, d, i;
    int count = 0;
    scanf("%d %d %d", &L, &R, &d);

    for(i = L; i <= R; i++){
        if(i % d == 0){
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}