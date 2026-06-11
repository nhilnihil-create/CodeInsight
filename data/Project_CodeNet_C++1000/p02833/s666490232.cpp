#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

ll n;

ll cnt(ll x)
{
    ll res = 0;
    for (ll y = 1; y <= n / x; y *= x)
    {
        res += n / (y * x);
    }

    return res;
}

int main()
{

    std::cin >> n;

    if (n % 2)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    n /= 2;

    std::cout << std::min(cnt(2) + n, cnt(5)) << std::endl;

    return 0;
}