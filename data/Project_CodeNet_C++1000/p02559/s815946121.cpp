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
#include <atcoder/fenwicktree>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
using namespace atcoder;
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
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<long long> f(N);
    int a, b, c;
    long long x = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        f.add(i, x);
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            f.add(b, c);
        }
        else
        {
            long long k = f.sum(b, c);
            cout << k << endl;
        }
    }

    return 0;
}
