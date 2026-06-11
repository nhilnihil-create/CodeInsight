#include <stdio.h>
 
int main()
{
    int n;
    long long a[100001];
    long long max = 1000000000000000000;
    long long mul = 1;
 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] == 0)
        {
            printf("0");
            return 0;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            printf("-1");
            return 0;
        }
        mul *= a[i];
        max /= a[i];
 
        
    }
    printf("%lld", mul);
    return 0;
}