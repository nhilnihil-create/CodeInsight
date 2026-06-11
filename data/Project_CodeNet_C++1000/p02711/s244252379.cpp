#include <stdio.h>

int main(){
    int n, x,y,z;
    scanf("%d", &n);
    x = n / 100;
    y = ((n-(x*100))/10);
    z = n-(x*100)-(y*10);
    if(x == 7 | y == 7 | z == 7){
        puts("Yes");
    }
    else {
        puts("No");
    }
    return 0;
}