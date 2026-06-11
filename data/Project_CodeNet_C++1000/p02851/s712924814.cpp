#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= n; ++i)

int main()
{
    ll n, k;

    std::cin >> n >> k;

    std::vector<ll> a(n + 1);
    std::vector<int> mods(n + 1);

    rep(i, n)
    {
        std::cin >> a[i];
        a[i] += a[i - 1] - 1;
        mods[i] = a[i] % k;
    }

    ll ans = 0;

    std::map<int, ll> mp;

    mp[0] = 1;

    rep(i, n)
    {
        if (i >= k)
        {
            --mp[mods[i - k]];
        }
        ans += mp[mods[i]];
        ++mp[mods[i]];
    }

    std::cout << ans << std::endl;

    return 0;
}