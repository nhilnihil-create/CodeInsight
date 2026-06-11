#include <stdio.h>

int main(){
    int H, A;
    
    scanf("%d %d", &H, &A);
    H%A == 0 ?H = H/A :H = H/A+1;
    printf("%d", H);
    return 0;
}