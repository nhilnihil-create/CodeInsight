#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

// べき乗

long long power(long long x, long long y)
{
    long long ret = 1;
    while(y > 0)
    {
        if (y & 1)
        {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

// combination

long long combination(long long x, long long y)
{
    long long xcy = 1;
    long long invxcy = 1;
    for (long long i = 1; i <= y; i++)
    {
        xcy = ((xcy * (x - i +1))) % mod;
        invxcy = invxcy * i % mod;
    }
    xcy = xcy * power(invxcy, mod-2) % mod;
    return xcy;
}

int main(void)
{
    long long X, Y;
    cin >> X >> Y;

    if (((2 * X) - Y) % 3 != 0 || (2 * X) - Y < 0 || ((2 * Y) - X) % 3 != 0 || (2 * Y) - X < 0)
    {
        cout << 0 << endl;
        exit(0);
    }

    long long x = ((2 * X) - Y) / 3;
    long long y = ((2 * Y) - X) / 3;
    long long ans = combination(x + y, x);
    cout << ans << endl;
}