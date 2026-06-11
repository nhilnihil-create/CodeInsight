#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n, p = 2;
    int count = 0;
    cin >> n;
    long long cpy = n;
    for (long long i = 2; i * i <= cpy; i++)
    {
        if (n % i == 0)
        {
            p = i;
            for (long long j = 1; n % i == 0; j++)
            {
                if (((n / p) % (p * i)) == 0 || (n / p) % i != 0)
                {
                    n /= p;
                    count++;
                }
                p *= i;
            }
            
        }
        if (n == 1)
            break;
    }
    if (n == 1)
        printf("%d", count);
    else
        printf("%d", count + 1);
}