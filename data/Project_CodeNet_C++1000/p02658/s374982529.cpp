#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    long long int arr[num],mul = 1;
    for (int i = 0; i < num; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] == 0)
        {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (mul > 1000000000000000000/arr[i])
        {
            printf("-1\n");
            return 0;
        }
        mul *= arr[i];
    }
    printf("%lld\n", mul);
    return 0;
}
