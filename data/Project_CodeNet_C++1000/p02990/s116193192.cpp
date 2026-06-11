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

const int MAX = 2000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long nHm(int n, int m)
{
    return fac[n] * (finv[n - m] * finv[m] % MOD) % MOD;
}

int main()
{
    COMinit();

    lint n, k;

    scanf("%lld", &n);
    scanf("%lld", &k);

    for (int i = 0; i < k; ++i)
    {
        if (n - k + 1 < i + 1)
        {
            printf("%d\n", 0);
        }
        else
        {
            lint b = nHm(k - 1, i + 1 - 1);
            lint r = nHm(n - k + 1, i + 1);
            printf("%lld\n", b * r % MOD);
        }
    }

    return 0;
}
