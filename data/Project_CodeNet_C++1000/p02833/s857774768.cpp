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

static large solve(large N) {
    if (N % 2 == 1)
        return 0;
    if (N < 10)
        return 0;

    auto fives = 0LL;
    for (auto x = 10LL; x <= 1'000'000'000'000'000'000; x *= 5) {
        fives += N / x;
    }
    return fives;
}

int main() {
    large N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}
