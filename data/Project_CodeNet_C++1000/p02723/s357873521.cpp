#include <stdio.h>

int main()
{
    char S[20];
    scanf("%s", &S);
    getchar();
    if (S[2] == S[3] && S[4] == S[5])
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}