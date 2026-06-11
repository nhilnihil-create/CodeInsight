#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    double arr[n+5], sum=0, dif;
    arr[0]=0;
    for(i=1; i<=n; i++)
    {
        scanf("%lf", &arr[i]);
        if(arr[i]<arr[i-1])
        {
            dif = arr[i-1]-arr[i];
            sum = sum + dif;
            arr[i] = arr[i-1];
        }
    }
    printf("%.0lf\n", sum);

    return 0;
}
