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

int main()
{
    int n;
    cin >> n;
    auto a = vector<int>(n);
    for (auto& a_i : a) {
        cin >> a_i;
    }

    auto factors = vector<vector<int>>(1'000'005);
    for (int a_i = 1; a_i <= 1'000'000; ++a_i) {
        auto x = a_i;
        factors[a_i].push_back(1);

        if (x % 2 == 0) {
            do { x /= 2; } while (x % 2 == 0);
            factors[a_i].push_back(2);
        }
        if (x % 3 == 0) {
            do { x /= 3; } while (x % 3 == 0);
            factors[a_i].push_back(3);
        }

        for (int d = 5; d * d <= x;) {
            if (x % d == 0) {
                do { x /= d; } while (x % d == 0);
                factors[a_i].push_back(d);
            }
            d += 2;
            if (x % d == 0) {
                do { x /= d; } while (x % d == 0);
                factors[a_i].push_back(d);
            }
            d += 4;
        }

        if (x > 1) {
            factors[a_i].push_back(x);
        }
    }

    auto factor_count = vector<int>(1'000'005);
    for (auto a_i : a) {
        for (auto f : factors[a_i]) {
            factor_count[f]++;
        }
    }

    auto sharing = 0;
    for (auto f = 1; f <= 1'000'000; ++f) {
        if (f == 1) continue;
        sharing = max(sharing, factor_count[f]);
    }
    if (sharing <= 1) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    if (sharing < n) {
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
    return 0;
}
