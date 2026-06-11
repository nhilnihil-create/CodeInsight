#include <stdio.h>
#include <string.h>

int main () {
    
    char x[12];
    char y[12];
    scanf("%s%s", &x,&y);
    int a,b;
    scanf("%d%d", &a,&b);
    char z[12];
    scanf("%s",&z);
    
    if(strcmp(z,x)==0) {
        printf("%d %d\n",a-1,b);    
    }
    else if(strcmp(z,y)==0) {
        printf("%d %d\n",a,b-1);
    }

    return 0;
}