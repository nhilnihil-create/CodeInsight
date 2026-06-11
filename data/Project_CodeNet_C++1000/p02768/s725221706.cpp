//Bouquet problem

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sd second
#define ft first
#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int p = 1e9 + 7;

// Fast Exponentiation

int fast_pow(int a, int n, int p)
{
    int res = 1;
    a %= p;
    if (a == 0)
        return 0;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

// Modular Inverse

int modInverse(int a, int p)
{
    return fast_pow(a, p - 2, p);
}

// Fermat's Little Method ncr calculation

int ncrfermat(int n, int r, int p)
{
    if (r == 0)
        return 1;

    if (r > (n - r))
        r = n - r;

    int x = 1, y = 1;

    for (int i = 0; i < r; i++)
    {
        x = (x * (n - i)) % p;
        y = (y * (i + 1)) % p;
    }
    return (x * (modInverse(y, p) % p)) % p;
}

int32_t main()
{
    ios;
    int n, a, b;
    cin >> n >> a >> b;
    int sum = fast_pow(2, n, p) - 1;
    sum = (sum - (ncrfermat(n, a, p) + ncrfermat(n, b, p))) % p;
    cout << (sum + p) % p << endl;
    return 0;
}
