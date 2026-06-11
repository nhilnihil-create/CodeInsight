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

int main() {
    int n, m;
    cin >> n >> m;
    auto a = vector<int>(n);
    for (auto& ai : a) {
        cin >> ai;
        ai /= 2;
    }

    const auto exp2 = [](auto x) {
        auto cnt = 0;
        while ((x & 1) == 0) {
            x >>= 1;
            ++cnt;
        }
        return cnt;
    };
    auto mn = large{exp2(a[0])};
    auto mx = large{exp2(a[0])};
    for (auto ai : a) {
        auto e2 = large{exp2(ai)};
        mn = min(mn, e2);
        mx = max(mx, e2);
    }
    if (mn != mx) {
        cout << 0 << endl;
        return 0;
    }

    mn = 1LL << mn;
    for (auto& ai : a) {
        ai /= mn;
    }
    auto l = 1LL;
    for (auto ai : a) {
        l = lcm(l, large(ai));
        if (l > m) {
            cout << 0 << endl;
            return 0;
        }
    }

    auto x = l * mn;
    auto x1 = m / x;
    auto x2 = m / (2 * x);

    cout << (x1 - x2) << endl;
    return 0;
}