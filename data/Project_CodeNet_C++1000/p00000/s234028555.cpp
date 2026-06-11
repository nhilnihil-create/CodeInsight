#include <stdio.h>
 
int main(){
    int i, j, a;
    for(i = 1; i < 10; i++){
        for(j = 1; j < 10; j++){
            a = i * j;
            printf("%dx%d=%d\n", i, j, a);
        }
    }
    return 0;
} 