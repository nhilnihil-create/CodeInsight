#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int64_t read_int() {
    int64_t ret = 0, sgn = 1;
    int ch = getchar_unlocked();
    while (isspace(ch)) { ch = getchar_unlocked(); }
    if (ch == '-') { sgn = -1; ch = getchar_unlocked(); }
    for (; isdigit(ch); ch = getchar_unlocked())
        ret = (ret * 10) + (ch - '0');
    ungetc(ch, stdin);
    return sgn * ret;
}

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()

template <typename T> inline void assign_min(T& x, const T& value) noexcept { x = min(x, value); }
template <typename T> inline void assign_max(T& x, const T& value) noexcept { x = max(x, value); }

constexpr char LF = '\n';

//-------------------------------------------------------------------------------------------------

int main() {
    int N = read_int();
    vector<int64_t> A(N);
    REP(i, N) A[i] = read_int();

    // i < j とすると
    //   j - i = A[j] + A[i]
    //   ∴ j - A[j] = A[i] + i

    map<int64_t, int64_t> B;
    REP(i, N) B[A[i] + i] += 1;

    int64_t ans = 0;
    REP(j, N) ans += B[j - A[j]];
    cout << ans << LF;
}
