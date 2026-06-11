#include <stdio.h>

int kuadrat(int a, int b)
{
    int total = 1;
    while(b > 0){
        total *= a;
        b--;
    }
    return total;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    long long int arr[cases], total = 1;

    int i = 0;
    char temp;
    do
    {
        scanf("%lld%c", &arr[i], &temp);
        if(arr[i] == 0){
            printf("0");
            return 0;
        }
        i++;
    } while (temp != '\n');
    
    for(int j = 0; j < cases; j++){
        if (total > 1000000000000000000 / arr[j])
        {
            printf("-1");
            return 0;
        }
        else
        {
            total *= arr[j];
        }
    }
    printf("%lld", total);

    return 0;
}