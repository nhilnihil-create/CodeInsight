#include<stdio.h>
#include<string.h>

int main(void){
    char S[12];
    char T[12];
    int A,B;
    char U[12];

    scanf("%s", &S);
    scanf("%s", &T);
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%s", &U);

    if(strcmp(S, U) == 0){
        A--;
        printf("%d %d\n", A, B);
    }else if(strcmp(T, U) == 0){
        B--;
        printf("%d %d\n", A, B);
    }
    return 0;
}