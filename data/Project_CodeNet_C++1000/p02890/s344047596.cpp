#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= (n); ++i)
#define rag(con) std::begin(con), std::end(con)

int main()
{
    int n;

    std::cin >> n;

    std::map<int, int> mp;

    rep(i, n)
    {
        int a;
        std::cin >> a;
        mp[a]++;
    }

    std::vector<int> vec, sum;

    for (auto p : mp)
    {
        vec.push_back(p.second);
    }

    std::sort(rag(vec));

    sum.resize(vec.size());

    sum[0] = vec[0];

    rep(i, vec.size() - 1)
        sum[i] = sum[i - 1] + vec[i];

    rep(i, n)
    {
        int nn = n;
        while (1)
        {
            int mx = nn / i;
            int len = std::end(vec) - std::upper_bound(rag(vec), mx);
            int nnn = len * mx + sum[sum.size() - 1 - len];
            if (nnn == nn)
            {
                std::cout << nn / i << std::endl;
                break;
            }
            nn = nnn;
        }
    }

    return 0;
}