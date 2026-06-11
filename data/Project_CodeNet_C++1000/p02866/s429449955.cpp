#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

long long modpow(long long a, long long n, long long p)
{
    long long out = 1;
    while (n)
    {
        if (n & 1)
        {
            out = out * a % p;
        }
        a = a * a % p;
        n >>= 1;
    }
    return out;
}

int main()
{
    lint n;
    std::vector<lint> step(100000, 0);

    scanf("%lld", &n);

    for (int i = 0; i < n; ++i)
    {
        lint d;
        scanf("%lld", &d);

        if (i == 0 && d != 0)
        {
            printf("%d", 0);
            return 0;
        }

        step[d]++;
    }

    if (step[0] > 1)
    {
        printf("%d", 0);
        return 0;
    }

    lint done = 0;
    lint prev = 1;
    lint i = 0;

    lint ans = 1;
    lint mod = 998244353;

    while (done < n)
    {
        lint cur = step[i];
        if (cur == 0)
        {
            printf("%d", 0);
            return 0;
        }
        done += cur;

        ans *= modpow(prev, cur, mod);
        ans %= mod;

        prev = cur;
        i++;
    }

    printf("%lld", ans);

    return 0;
}
