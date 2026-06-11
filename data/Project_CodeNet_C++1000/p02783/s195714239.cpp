#include <stdio.h>

int main (){
    int h;
    int a;
    scanf("%d %d", &h , &a);
    int ans = h/a ;
    (h%a == 0) ? printf("%d", ans) : printf("%d", ans+1);

    return 0;
}