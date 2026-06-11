#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;

int64_t mypow(int64_t x, int64_t y)
{
    if (y == 1)
        return x;
    else if (y % 2 == 1)
        return mypow(x, y - 1) * x % mod;
    else
    {
        int64_t tmp = mypow(x, y / 2);
        return tmp * tmp % mod;
    }
}

int64_t soujo(int64_t x, int64_t y)//x~y
{
    if (x == y)
        return y;
    else
        return x * soujo(x + 1, y) % mod;
}

int64_t combi(int64_t x, int64_t y)//y C x,y < x
{
    int64_t X = soujo(x - y + 1, x);
    int64_t Y = soujo(1, y);
    return X * mypow(Y, mod - 2) % mod;
}

int main()
{
    int64_t N, A, B;
    cin >> N >> A >> B;

    int64_t ans = mypow(2, N) - 1;
    ans -= combi(N, A);
    ans -= combi(N, B);
    cout << (ans + mod * 2) % mod;
}