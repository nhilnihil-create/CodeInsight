#include <stdio.h>

int main()
{
    char input[10];
    scanf("%s", &input);
    ((input[2] == input[3]) && (input[4] == input[5])) ? puts("Yes") : puts("No");
    return 0;
}