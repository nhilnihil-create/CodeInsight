#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    ll k;

    std::cin >> n >> k;

    std::vector<ll> a(n), f(n);

    rep(i, n)
            std::cin >>
        a[i];

    rep(i, n)
            std::cin >>
        f[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(f), std::end(f), std::greater<>());

    constexpr ll INF = 1e15;

    ll lb = -1, ub = INF;

    auto g = [](ll x) { return (x > 0) ? x : 0; };

    while (ub - lb > 1)
    {
        ll mid = (lb + ub) / 2;
        ll cnt = 0;
        rep(i, n)
        {
            cnt += g(a[i] - mid / f[i]);
        }
        std::cerr << mid << ' ' << cnt << std::endl;
        if (cnt <= k)
            ub = mid;
        else
            lb = mid;
    }

    std::cout << ub << std::endl;

    return 0;
}