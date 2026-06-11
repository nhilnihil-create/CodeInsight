#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int k;

    scanf("%d", &k);
    scanf("%s", &s);

    if (k >= strlen(s)){
        printf("%s", s);
    }else if (k<strlen(s)){
    s[k]='\0';
    printf("%s...", s);
    }

}
