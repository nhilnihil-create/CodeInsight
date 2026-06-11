#include <stdio.h>

int main(){
    int h, w, n;
    scanf("%d", &h);
    scanf("%d", &w);
    scanf("%d", &n);
    
    int big;
    if(h>w){
        big = h;
    }
    else{
        big = w;
    }
    
    n%big ? printf("%d\n", n/big+1) : printf("%d\n", n/big);
    
    return 0;
}
