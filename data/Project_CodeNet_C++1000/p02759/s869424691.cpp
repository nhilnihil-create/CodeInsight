#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int b =(a%2==0) ? (a/2) : ((a/2)+1);
    printf("%d\n", b);
    
    return 0;
}