#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
}

lli gcd2(lli x, lli y)
{
    lli t;
    while (y != 0)
        t = x % y, x = y, y = t;
    return (x);
}

lli lcm2(lli x, lli y)
{
    lli xy = x * y;
    if (xy < 0)
        xy = -xy;
    return (xy / gcd2(x, y));
}

int main(void)
{
    lli a, b, c, d;
    cin >> a >> b >> c >> d;
    lli lcmcd = lcm2(c, d);
    lli numB = b - (lli)(b / c) - (lli)(b / d) + (lli)(b / lcmcd);
    lli numA = (a - 1) - (lli)((a - 1) / c) - (lli)((a - 1) / d) + (lli)((a - 1) / lcmcd);
    //lli numA = (a - 1) - (lli)((a - 1) / c) - (lli)((a - 1) / d) + (lli)((a - 1) / lcmcd));
    //n(9) = 7
    //40/6= 6;
    //40/8 = 5;
    //24
    //
    //6&8 = 48;
    //40
    //n(40) = 29
    cout << numB - numA;
    return 0;
}
