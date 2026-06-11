#include <stdio.h>
#include <string.h>

int main(){
    char S[15], T[15], U[15];
    int a, b;
    
    scanf("%s %s", S, T);
    scanf("%d %d", &a, &b);
    scanf("%s", U);
    
    (strcmp(U, S) == 0) ? a-- : b--;
    printf("%d %d", a, b);
    
    return 0;

}