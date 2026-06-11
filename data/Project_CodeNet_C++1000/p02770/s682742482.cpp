#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>

using namespace std;

long long mod = 1000000007;

long long binpow(long long x, long long k)
{
    if (k == 0)
    {
        return 1LL;
    }
    long long temp = binpow(x, k / 2);
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
    return binpow(x, mod - 2);
}

long long binomial(long long n, long long k)
{
    long long rez = 1;
    for (long long i = n - k + 1; i <= n; i++)
    {
        rez *= i;
        rez %= mod;
    }
    long long temp = 1;
    for (long long i = 1; i <= k; i++)
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
    long long k, q;
    cin >> k >> q;
    vector<long long> d(k), temp(k);
    long long n, x, m, zerocnt, sm, rez;
    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> n >> x >> m;
        zerocnt = 0;
        sm = 0;
        rez = 0;
        for (int j = 0; j < k; j++)
        {
            temp[j] = d[j] % m;
            if (temp[j] == 0)
            {
                zerocnt++;
            }
            sm += temp[j];
        }
        sm *= ((n - 1) / k);
        rez += n - 1;
        rez -= zerocnt * ((n - 1) / k);
        for (int j = 0; j < (n - 1) % k; j++)
        {
            sm += temp[j];
            if (temp[j] == 0)
            {
                rez--;
            }
        }
        sm += x % m;
        rez -= sm / m;
        cout << rez << '\n';
    }
    return 0;
}
