#include<cstdio>
#include<cstring>

int GCD(long long n1, long long n2);

int main()
{
    long long a, b;
    long long num;
    scanf("%lld %lld", &a, &b);
    num = GCD(a, b);
    printf("%lld", a / num * b);
    return 0;
}

int GCD(long long n1,long long n2)
{
    return n1 % n2 ? GCD(n2, n1 % n2) : n2;
}