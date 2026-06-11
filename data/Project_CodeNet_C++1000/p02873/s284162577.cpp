#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    long ans = 0;

    char s[500001];
    scanf("%s", s);

    int a[strlen(s) + 1] = {0};
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == '<')
            a[i + 1] = max(a[i] + 1, a[i + 1]);
    /*
    for (int i = 0; i < strlen(s) + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
    */

    for (int i = strlen(s); i > 0; i--)
        if (s[i - 1] == '>')
            a[i - 1] = max(a[i] + 1, a[i - 1]);
    /*
    for (int i = 0; i < strlen(s) + 1; i++)
        printf("%d ", a[i]);
    printf("\n");
    */

    for (int i = 0; i < strlen(s) + 1; i++)
        ans += a[i];
    printf("%ld\n", ans);

    return 0;
}