#include <stdio.h>
int main(){
    char string1[103];
    char string2[103];

    scanf("%s %s", string1, string2);
    printf("%s%s\n", string2, string1);

    return 0;
}