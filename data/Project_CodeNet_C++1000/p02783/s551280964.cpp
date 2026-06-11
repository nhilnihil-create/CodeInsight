#include <stdio.h>

int main(){
    int H;
    int A;
    scanf("%d %d", &H, &A);
    printf("%d", H%A == 0 ? H/A : H/A + 1);
 
    return 0;
}