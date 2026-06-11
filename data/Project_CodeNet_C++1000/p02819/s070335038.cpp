#include<stdio.h>//khata

int isPrime(int n)
{
    int i;

    if(n <= 1)
        return 0;
    for(i=2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int finding_prime(int n)
{
    while(isPrime(n) != 1)
    {
        n++;
    }

    return n;
}

int main()
{
    int x, returned;

    scanf("%d", &x);

    returned = isPrime(x);

    if(returned == 1)
        printf("%d\n", x);

    else if(returned == 0)
    {
        x=finding_prime(x);
    }

    if(returned == 0)
        printf("%d\n", x);

    return 0;
}





