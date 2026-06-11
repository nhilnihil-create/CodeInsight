#include <stdio.h>
#include <string.h>
int main(){
    int a;
    scanf("%d", &a);
    getchar();
    char string[105];
    scanf("%[^\n]", string);
    int len = strlen(string);
    // if(len > a){
    //     strcpy(string + a, "...");
    // }
    // printf("%s\n", string);
    for(int i = 0; i <= a && string[i] != '\0'; i++){
        if(i == a){
            printf("...");
            break;
        }
        else{
            printf("%c", string[i]);
        }
    }
    printf("\n");
    return 0;
}