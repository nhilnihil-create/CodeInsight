#include <stdio.h>
#include <string.h>

int main(){
    char kalimat[100];
    int limit;
 
    scanf("%d\n%[^\n]", &limit, &kalimat);
    int length = strlen(kalimat);
       if(length <= limit){
        printf("%s", kalimat);
        } else {
            for(int a = 0; a < limit; a++){
            printf("%c", kalimat[a]);
            
        } 
    puts("...");
        }
    return 0;
}