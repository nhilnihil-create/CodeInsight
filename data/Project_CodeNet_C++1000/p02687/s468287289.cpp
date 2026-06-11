#include <stdio.h>
#include <string.h>

int main(){
    char type[30];

    scanf("%s", type);
    if(strcmp (type, "ABC") == 0){
        printf("ARC\n");
    } else {
        printf("ABC\n");
    }
    return 0;
}