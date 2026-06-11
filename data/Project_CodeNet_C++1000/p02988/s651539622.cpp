#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define PY "YES\n"    // printf(PY);
#define PN "NO\n"     // printf(PN);

int main()
{
    int n, count=0, i;
    scanf("%d", &n);
    int arr[n+5];

    for(i=1; i<=n; i++)
        scanf("%d", &arr[i]);


    for(i=2; i<n; i++)
    {
        if(arr[i]<arr[i-1] && arr[i]>arr[i+1])
            count++;
        else if(arr[i]>arr[i-1] && arr[i]<arr[i+1])
            count++;
    }

    printf("%d\n", count);

    return 0;
}
