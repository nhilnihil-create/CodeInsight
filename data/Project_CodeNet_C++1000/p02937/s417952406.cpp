#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::map<char, std::vector<int>> mp;

    rep(i, s.size())
    {
        mp[s[i]]
            .push_back(i);
    }

    int pos = -1, ans = 0;

    for (int i = 0; i < t.size();)
    {
        const auto &mmp = mp[t[i]];
        if (mmp.empty())
        {
            std::cout << -1 << std::endl;
            return 0;
        }
        auto it = std::upper_bound(std::begin(mmp), std::end(mmp), pos);
        if (it == mmp.end())
        {
            ++ans;
            pos = -1;
        }
        else
        {
            pos = *it;
            ++i;
        }
        //std::cerr << pos << std::endl;
    }

    std::cout << ans * s.size() + pos + 1 << std::endl;

    return 0;
}