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
    int n, k;
    string s;
    cin >> n >> k >> s;
    auto v = vector<int>(n + 2);

    auto parts = vector<int>();
    parts.push_back(1);
    auto last = s[0];
    for (auto i = 1; i < n; ++i) {
        if (s[i] == last) {
            parts.back()++;
            continue;
        }

        parts.push_back(1);
        last = s[i];
    }

    for (auto i = 0; i < k; ++i) {
        if (parts.size() <= 1)
            break;

        if (parts.size() == 2) {
            parts.front() += parts.back();
            parts.pop_back();
            break;
        }

        auto last = parts[parts.size() - 1];
        auto secondlast = parts[parts.size() - 2];

        parts[parts.size() - 3] += last + secondlast;
        parts.resize(parts.size() - 2);
    }

    auto sum = accumulate(parts.begin(), parts.end(), 0LL, [](auto sum, auto item) { return sum + max(0, item - 1); });
    cout << sum << endl;
    return 0;
}
