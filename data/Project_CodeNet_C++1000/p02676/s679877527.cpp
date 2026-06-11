#include <stdio.h>
#include <string.h>
int main(){
    int a;
    scanf("%d", &a);
    getchar();
    char string[105];
    scanf("%[^\n]", string);
    int len = strlen(string);
    if(len > a){
        strcpy(string + a, "...");
    }
    printf("%s\n", string);
    return 0;
}