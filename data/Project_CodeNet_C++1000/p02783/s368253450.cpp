#include <stdio.h>

int main() {

    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d", (x % y == 0 ? x / y : x / y+1));
    // if(x % y == 0) {
    //     printf("%d\n", x / y);
    // } else {
    //     printf("%d", x / y+1);
    // }

    return 0;
}