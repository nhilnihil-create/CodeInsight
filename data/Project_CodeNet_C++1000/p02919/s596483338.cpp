#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= (n); ++i)

int main()
{
    int n;

    std::cin >> n;

    std::vector<ll> p(n + 1), pos(n + 1);

    rep(i, n)
    {
        std::cin >>
            p[i];
        pos[p[i]] = i;
    }

    ll ans = 0;

    std::multiset<ll> set;

    set.insert(0);
    set.insert(n + 1);
    set.insert(pos[n]);

    for (int i = n - 1; i >= 1; --i)
    {
        ll x = pos[i];
        auto it1 = set.lower_bound(x);
        it1--;
        auto it3 = set.upper_bound(x);
        if (it1 != set.begin())
        {
            auto it2 = it1;
            it2--;

            ans += i * (*it3 - x) * ((*it1) - (*it2));
        }

        auto it4 = it3;
        ++it4;

        if (it4 != set.end())
        {

            ans += i * (x - *it1) * ((*it4) - (*it3));
        }

        set.insert(pos[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}