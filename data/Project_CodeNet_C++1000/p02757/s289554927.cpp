#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, p;

    std::cin >> n >> p;

    std::string s;

    std::cin >> s;

    auto g = [](char ch) { return atoi(&ch); };

    if (p == 2 || p == 5)
    {
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (g(s[i]) % p == 0)
                ans += i + 1;
        }
        std::cout << ans << std::endl;
    }
    else
    {
        std::vector<int> p10(p - 1);

        int x = 1;

        rep(i, p - 1)
        {
            p10[i] = x;
            x = x * 10 % p;
            //std::cerr << p10[i] << ' ';
        }
        //std::cerr << std::endl;

        int mod = 0;
        std::map<int, ll> mp;

        for (int i = n - 1; i >= 0; --i)
        {
            mod += g(s[i]) * p10[(n - 1 - i) % (p - 1)];
            mod %= p;
            ++mp[mod];
            //std::cerr << i << ' ' << mod << std::endl;
        }
        ll ans = 0;
        for (auto p : mp)
        {
            if (p.first == 0)
                ans += p.second;
            ans += p.second * (p.second - 1) / 2;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}