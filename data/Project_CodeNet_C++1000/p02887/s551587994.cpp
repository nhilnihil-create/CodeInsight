#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    char s[100010]; scanf("%s", s);

    int count = 1;

    for (int i=1; i<n; i++)
    {
        if (s[i] != s[i-1]) count++;
    }

    printf("%d\n", count);
}