#include <stdio.h>
#include <string.h>

int main(){
    int K; 
    char str[100];
    scanf("%d", &K);
    scanf("%s", str);
   int len = strlen(str);
    if(len > K){
        for(int i = 0; i < K; i++){
            printf("%c", str[i]);
        }
        printf("...\n");
    } else {
        printf("%s", str);
    }
    return 0;
}