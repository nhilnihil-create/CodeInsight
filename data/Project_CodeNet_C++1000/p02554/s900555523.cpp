#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)

#define pi(x) printf("%d", x)

int main()
{
    ll t, n, count = 0, m;
    sll(n);

    ll a10 = 1, a9 = 1, a8 = 1, prime = 1000000007;

    for (ll i = 0; i < n; i++)
    {
        a10 = (a10 % prime * 10) % prime;
        a9 = (a9 % prime * 9) % prime;
        a8 = (a8 % prime * 8) % prime;
    }

    a9 = (2 * a9 % prime) % prime;

    ll ans = (a10 % prime - a9 % prime + a8 % prime) % prime;
    if (ans < 0)
    {
        ans += prime;
    }

    cout << ans << endl;

    return 0;
}