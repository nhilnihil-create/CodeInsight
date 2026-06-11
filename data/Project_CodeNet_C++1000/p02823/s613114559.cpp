/*
Author: Xjrjyy
LANG: C++
PROG: agc041_a.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>

#define MAXN ()

long long n, a, b;

long long abs(long long x) { return x >= 0 ? x : -x; }

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    if (abs(a - b) & 1)
    {
        long long ta = std::min(a - 1, n - a);
        long long tb = std::min(b - 1, n - b);
        printf("%lld\n", (abs(a - b) >> 1) + std::min(ta, tb) + 1);
    }
    else
    {
        printf("%lld\n", abs(a - b) >> 1);
    }
    return 0;
}
