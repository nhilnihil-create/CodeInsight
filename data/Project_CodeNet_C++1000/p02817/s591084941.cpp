#include <stdio.h>

int main(){
    char first_name[105];
    char last_name[105];

    scanf("%s %s\n", &first_name, &last_name);

    printf("%s%s\n", last_name, first_name);

    return 0;
}