#include <stdio.h>
#include <string.h>

int main(){
    int a;
    char k [101];
    scanf("%d", &a);
    scanf("%s", k);
    int len = strlen(k);
    if (len <= a) {
        printf("%s\n", k);
    }
    else{
        for(int i=0; i < a; i++){
            printf("%c",k[i]);

        }
        puts("...\n");
    }
    
    return 0;
}