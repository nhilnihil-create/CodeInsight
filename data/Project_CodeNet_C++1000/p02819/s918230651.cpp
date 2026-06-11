#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

//素数判定
#include <stdbool.h>
#include <math.h>

bool IsPrimeNumber(long n)
{
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;

    int r = (long)sqrt((double)n);

    for (int i = 3; i <= r; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ll x;
    cin >> x;
    while (true)
    {
        if (IsPrimeNumber(x))
            break;
        else
            x++;
    }
    cout << x << endl;
    return 0;
}
