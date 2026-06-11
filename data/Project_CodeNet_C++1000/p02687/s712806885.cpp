#include <stdio.h>

int main()
{
    char s[5];
    scanf("%s", &s);
    switch (s[1])
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