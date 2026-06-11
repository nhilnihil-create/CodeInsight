#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int n1 = n / 100;
    int n2 = (n % 100) / 10;
    int n3 = n % 10;
    if (n1 == 7 || n2 == 7 || n3 == 7)
    {
        printf("Yes", n);
    }
    else
    {
        printf("No", n);
    }
    return 0;
}