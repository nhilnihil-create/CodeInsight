#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char s;
    double sum=0, m;

    while(scanf("%c", &s))
    {
        if(s=='\n')
            break;
        sum = sum + s-48.0;
    }
    m = fmod(sum, 9);
    if(m==0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
