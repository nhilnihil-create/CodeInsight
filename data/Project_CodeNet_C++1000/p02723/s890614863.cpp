#include <stdio.h>

int main()
{
    char b[10];
    scanf("%s", &b);
    if (b[2] == b[3] && b[4] == b[5])
    {
        printf("Yes\n");
    }
     else 
	{
        printf("No\n");
    }
    return 0;
}
