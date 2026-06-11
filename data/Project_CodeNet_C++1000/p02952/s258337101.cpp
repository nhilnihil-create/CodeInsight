#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define PY "Yes\n"    // printf(PY);
#define PN "No\n"     // printf(PN);

int main()
{
    int n, ans;
    scanf("%d", &n);
    if(n<10)
        ans = n;
    else if(n>=10 && n<=99)
        ans = 9;
    else if(n>=100 && n<=999)
        ans = 9 + n-99;
    else if(n>=1000 && n<=9999)
        ans = 909;
    else if(n>=10000 && n<=99999)
        ans = n-9999 + 909;
    else
        ans = 90909;
        
    printf("%d\n", ans);
    return 0;
}
