#include <stdio.h>

int main () {
    int H ;
    int A ;
    int dead ;
    scanf("%d %d", &H, &A) ;
    dead=H%A==0? dead=H/A : dead=H/A+1 ;
    printf("%d", dead) ;

    return 0 ; 
}