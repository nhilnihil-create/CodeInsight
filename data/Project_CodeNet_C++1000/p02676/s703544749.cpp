#include <stdio.h>
#include <string.h>
 
int main(){
    int k;
    char s[102];
 
    scanf("%d", &k);
    scanf("%s", s);
    
    if (strlen(s) <= k) {
        printf("%s", s);
    }
    else{
        for (int i=0; i < k; i++) {
            printf("%c", s[i]);
        }
        printf("...");
    }
 
    return 0;
}