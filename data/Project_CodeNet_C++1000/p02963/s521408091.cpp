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

int main()
{

    lint s;

    scanf("%lld", &s);

    lint thr = 1e9;

    if (s <= thr)
    {
        printf("%lld %lld %lld %lld %lld %lld", 0ll, 0ll, s, 0ll, 0ll, 1ll);
    }
    else
    {
        lint bc = (thr - s % thr) % thr;
        lint a = thr;
        lint d = (s + bc) / thr;
        lint b = 1;
        lint c = bc;
        printf("%lld %lld %lld %lld %lld %lld\n", 0ll, 0ll, a, b, c, d);
    }

    return 0;
}
