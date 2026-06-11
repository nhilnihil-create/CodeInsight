

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char str[102];

    scanf("%d", &n);
    scanf("%s", str);
    
    if (strlen(str) <= n){
        printf("%s", str);
    }
    else{
        for (int i=0; i<n; i++){
            printf("%c", str[i]);
        }
        printf("...");
    }

    return 0;
}
