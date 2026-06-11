#include <stdio.h>
int main(){
    char input[5];
    scanf("%s", input);
    switch (input[1])
    {
        case 'B':
        printf("ARC\n");
        break;
        case 'R':
        printf("ABC\n");
        break;
    }
    return 0;
}