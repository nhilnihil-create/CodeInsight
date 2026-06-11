#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int d[(int)1e6 + 10][2];

int main()
{
    std::string s;

    std::cin >> s;

    std::vector<int> vec;

    for (char ch : s)
        vec.emplace_back(atoi(&ch));

    std::reverse(std::begin(vec), std::end(vec));

    vec.push_back(0);

    int n = vec.size();

    d[0][0] = vec[0];
    d[0][1] = 10 - vec[0];

    for (int i = 1; i < n; ++i)
    {
        d[i][0] = std::min(d[i - 1][0] + vec[i], d[i - 1][1] + vec[i] + 1);
        d[i][1] = std::min(d[i - 1][0] + 10 - vec[i], d[i - 1][1] + 9 - vec[i]);
    }

    std::cout << d[n - 1][0] << std::endl;

    return 0;
}