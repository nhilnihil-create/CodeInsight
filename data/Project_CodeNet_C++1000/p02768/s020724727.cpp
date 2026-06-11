#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
long long int wari = 1000000007;
const int MAX = 510000;

long long int fac[MAX], finv[MAX], inv[MAX];

long long int twopow(long long int n);
long long int COM(long long int n, long long int k);
void COMinit();

int main(void)
{
    long long int n, a, b, res;
    cin >> n >> a >> b;
    COMinit();
    res = (twopow(n) - 1);
    // cout << res << endl;
    res = res - COM(n, a) - COM(n, b);
    // cout << res << endl;
    res = res % wari;
    // cout << res << endl;
    if (res < 0)
        res += wari;
    cout << res << endl;
    return 0;
}

long long int twopow(long long int n)
{
    if (n == 1)
    {
        return 2;
    }
    else if (n % 2 == 1)
    {
        long long int a;
        a = twopow(n / 2) % wari;
        return (a * a * 2) % wari;
    }
    else
    {
        long long int a;
        a = twopow(n / 2) % wari;
        return (a * a) % wari;
    }
}

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % wari;
        inv[i] = wari - inv[wari % i] * (wari / i) % wari;
        finv[i] = finv[i - 1] * inv[i] % wari;
    }
}

long long int COM(long long int n, long long int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    long long int res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res %= wari;
    }
    return res * (finv[k] % wari) % wari;
}