#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define size 100005

int main()
{
    int n, i, arr[size], count=0, temp, a, b, pos_1, pos_2, flag=0;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    for(i=1; i<n; i++)
    {
        if(arr[i]>arr[i+1])
            count++;
    }
    if(count==1)
    {
        for(i=1; i<n; i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    else if(count==2)
    {
        for(i=1; i<n; i++)
        {
            if(arr[i]>arr[i+1])
            {
                pos_1 = i;
                a = arr[pos_1];
                break;
            }
        }
        for(i=pos_1+1; i<n; i++)
        {
            if(arr[i]>arr[i+1])
            {
                pos_2 = i+1;
                b = arr[pos_2];
                break;
            }
        }
        arr[pos_1] = b;
        arr[pos_2] = a;
    }

    for(i=1; i<n; i++)
    {
        if(arr[i]>arr[i+1])
            flag++;
    }

    if(flag==0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
