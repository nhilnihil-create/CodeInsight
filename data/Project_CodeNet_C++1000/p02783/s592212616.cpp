#include <stdio.h>

int main(){
    int h, a;
    int hit = 0;
    scanf("%d %d", &h, &a);
    hit = h/a;
    if(h%a != 0){
        hit++;
    }
    printf("%d\n", hit);
    
    return 0;
}
