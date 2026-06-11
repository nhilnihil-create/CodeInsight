#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

int pow_mod_2019(int y)
{
    int ans = 1;
    for (int i = 0; i < y; i++)
    {
        ans = (ans * 10) % 2019;
    }
    return ans;
}

int main()
{
    std::string S;
    std::cin >> S;
    // S = 2019
    // T[0] = 9;
    // T[1] = 19;
    // T[2] = 19;
    // T[3] = 2019;

    // T[i] - T[j] mod 2019 == 0
    // T[i] mod 2019 - T[j] mod 2019 == 0
    // T[i] == T[j] となるような (i, j) の個数

    std::vector<int> decimal(S.length());
    int d = 1;
    for (int i = 0; i < decimal.size(); i++)
    {
        decimal[i] = d;
        d = (d * 10) % 2019;
    }

    std::reverse(S.begin(), S.end());
    std::unordered_map<int, int> count;
    count[0] = 1;
    int x = 0;
    for (int i = 0; i < S.length(); i++)
    {
        x = ((S[i] - '0') * decimal[i] + x) % 2019;
        count[x]++;
    }
    int ans = 0;
    for (auto const &e : count)
    {
        int diff = e.second * (e.second - 1) / 2;
        ans += diff;
    }
    std::cout << ans << std::endl;
}