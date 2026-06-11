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

const int Rk = 0;
const int Sc = 1;
const int Pp = 2;

int main() {
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    auto total = 0;
    for (int i0 = 0; i0 < k; ++i0) {
        auto cnt = 1 + (n - 1 - i0) / k;
        if (cnt == 0)
            break;

        auto dp = vector<array<int, 3>>(cnt + 1);
        auto i = i0;

        for (auto j = 0; j < cnt; ++j, i += k) {
            if (t[i] == 'r') {
                dp[j + 1][Pp] = p + max(dp[j][Rk], dp[j][Sc]);
                dp[j + 1][Sc] = max(dp[j][Rk], dp[j][Pp]);
                dp[j + 1][Rk] = max(dp[j][Sc], dp[j][Pp]);
            }
            if (t[i] == 's') {
                dp[j + 1][Rk] = r + max(dp[j][Pp], dp[j][Sc]);
                dp[j + 1][Sc] = max(dp[j][Rk], dp[j][Pp]);
                dp[j + 1][Pp] = max(dp[j][Sc], dp[j][Rk]);
            }
            if (t[i] == 'p') {
                dp[j + 1][Sc] = s + max(dp[j][Rk], dp[j][Pp]);
                dp[j + 1][Pp] = max(dp[j][Rk], dp[j][Sc]);
                dp[j + 1][Rk] = max(dp[j][Sc], dp[j][Pp]);
            }
        }

        total += *max_element(dp[cnt].begin(), dp[cnt].end());
    }
    cout << total << endl;
    return 0;
}
