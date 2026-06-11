#include<stdio.h>
int main()
{
    int h, n;

    scanf("%d %d", &h, &n);

    int arr[100000];

    int sum=0;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);

        sum = sum + arr[i];
    }

    if(sum>=h)
    {
        printf("Yes\n");
    }

    else
    {
        printf("No\n");
    }

    return 0;
}