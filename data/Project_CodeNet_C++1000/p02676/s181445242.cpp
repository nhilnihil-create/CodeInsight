#include <stdio.h>
#include <string.h>

int main (){
    char S[100];
    int k;

    scanf("%d", &k);
    scanf("%s", S);
    int len = strlen(S);
    
    if(len <= k){
        printf("%s", S);
    }
    else{
        S[k] = '\0';
        printf("%s...", S);
    }
    
    return 0;
}