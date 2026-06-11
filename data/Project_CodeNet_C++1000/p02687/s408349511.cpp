#include <stdio.h>

int main() {

    char x[255];
    
    scanf("%s", x);
    if(x[1] == 'B') {
        printf("ARC\n");
    } else {
        printf("ABC\n");
    }

    return 0;
}