#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d", &N);
    char S[N+1];
    scanf("%s", &S);
    int len = strlen(S);
    if(len<2 || len%2==1){
        printf("No\n");
        return 0;
    }
    for(int i=0;i<(len/2);i++){
        if(S[i] != S[(len/2)+i]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}