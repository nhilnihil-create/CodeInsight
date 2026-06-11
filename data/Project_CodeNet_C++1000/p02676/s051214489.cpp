#include <stdio.h>
#include <string.h>
int main(){
    
    char S[101];
    int K;
    scanf("%d",&K);
    getchar();
    scanf("%[^\n]", &S);
    
    if (strlen(S) > K ){
        for(int i = 0; i < K; i++){
            printf("%c", S[i]);
        }
        printf("...\n");
    }else{
        for(int i = 0; i < strlen(S); i++){
            printf("%c", S[i]);
        }
    }
    return 0;
}