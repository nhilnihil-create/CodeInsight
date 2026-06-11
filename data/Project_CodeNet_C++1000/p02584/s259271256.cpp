#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef __int128 LL;
inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    LL x, k, d;
    x = read(), k = read(), d = read();

    if (x < 0)
        x = -x;
    if (x >= 0)
    {
        if ((x - k * d) >= 0)
        {
            print(x - k * d);
        }
        else
        {
            int t = (x / d);
            if ((k - t) % 2)
                print(-(x - d * t - d));
            else
                print(x - d * t);
        }
    }

    return 0;
}