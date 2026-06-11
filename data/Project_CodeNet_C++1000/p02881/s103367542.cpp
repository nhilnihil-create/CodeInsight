#include <stdio.h>
#include <math.h>

long long max_divisor(long long n)
{
    long long max_div = 1;
    long long max_len = (long long)sqrt(n);

    for (int i=max_len; i>=1; i--)
    {
        if (n % i == 0) return n / i;
    }

    return 1;
}

int main()
{
    long long n; scanf("%lld", &n);
    long long max_div = max_divisor(n);

    printf("%lld\n", max_div + n/max_div - 2);
}