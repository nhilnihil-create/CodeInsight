#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define PY "Yes\n"    // printf(PY);
#define PN "No\n"     // printf(PN);


int main()
{
    int h, n, i, sum=0;
    scanf("%d%d", &h, &n);
    int arr[n+5];
    for(i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }


    if(sum>=h)
        printf(PY);
    else
        printf(PN);

    return 0;
}
