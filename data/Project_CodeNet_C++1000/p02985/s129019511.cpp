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

int main() {
    int n, k;
    cin >> n >> k; // 100'000

    auto edge = vector<vector<int>>(n + 1);
    for (auto i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    auto distance = vector<int>(n + 1, -1);
    auto q = vector<int>(n + 1);
    auto push = 0;
    auto pop = 0;
    q[push++] = 1;
    distance[1] = 0;
    auto cases = large{k};
    while (pop < push) {
        auto v = q[pop++];
        auto d = distance[v] + 1;
        auto children = 0;

        auto x = k + (v == 1) - 2;

        for (auto n : edge[v]) {
            if (distance[n] < 0) {
                distance[n] = d;
                q[push++] = n;
                ++children;

                cases *= x;
                cases %= mod;
                x--;
            }
        }

        if (cases == 0)
            break;
    }

    cout << cases << endl;
    return 0;
}
