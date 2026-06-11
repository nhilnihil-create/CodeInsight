#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    scanf("%lld%lld", &n, &m);
    ll i = 1, j = n;
    for(; m > 0; i++, j--)
    {
        if((i - 1) - (j + 1) + i - j == -n - 2) j--;
        else if((i - 2) - (j + 2) + i - j == -n - 2) j--;
        printf("%lld %lld\n", i, j);
        m--;
    }
    return 0;
}
