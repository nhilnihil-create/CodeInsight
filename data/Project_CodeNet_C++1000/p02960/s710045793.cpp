#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;
constexpr auto mod = 1'000'000'007;

static array<array<int, 13>, 100'005> dp;

int main() {
    string s;
    cin >> s;

    dp[0][0] = 1;

    const auto n = int(s.length());
    for (auto i = 0; i < n; ++i) {
        fill(dp[i + 1].begin(), dp[i + 1].end(), 0);

        auto low = 0, high = 9;
        if (s[i] != '?')
            low = high = s[i] - '0';

        for (auto d = low; d <= high; ++d) {
            for (auto rem = 0; rem < 13; ++rem) {
                auto x = (rem * 10 + d) % 13;
                dp[i + 1][x] += dp[i][rem];
                dp[i + 1][x] %= mod;
            }
            continue;
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
