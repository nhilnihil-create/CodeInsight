#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;

long long mod = 1000000007;

long long pow(long long x, long long k)
{
    if (k == 0)
    {
        return 1LL;
    }
    long long temp = pow(x, k / 2);
    if (k % 2 == 1)
    {
        return (((temp * temp) % mod) * x) % mod;
    }
    else
    {
        return (temp * temp) % mod;
    }
}

long long modular_inverse(long long x)
{
    return pow(x, mod - 2);
}

long long binomial(long long n, long long k)
{
    long long rez = 1;
    for (int i = n - k + 1; i <= n; i++)
    {
        rez *= i;
        rez %= mod;
    }
    long long temp = 1;
    for (int i = 1; i <= k; i++)
    {
        temp *= i;
        temp %= mod;
    }
    rez *= modular_inverse(temp);
    rez %= mod;
    return rez;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sm1 = 0, sm2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sm1 += v[i];
    }
    long long rez = 999999999999999;
    for (int i = 0; i < n; i++)
    {
        rez = min(rez, abs(sm1 - sm2));
        sm2 += v[i];
        sm1 -= v[i];
    }
    rez = min(rez, abs(sm1 - sm2));
    cout << rez << '\n';
    return 0;
}
