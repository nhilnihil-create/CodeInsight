#include <stdio.h>

int main () {
    
    
    int a;
    int b;
    scanf("%d%d", &a,&b);
    
    if(a>=10) {
        printf("%d", b);
    }
    else if(a<10) {
        printf("%d",b+(100*(10-a)));
    }
    
    
    
    
    return 0;
}