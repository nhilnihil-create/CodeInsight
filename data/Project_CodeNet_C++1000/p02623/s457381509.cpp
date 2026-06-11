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

template <typename Int>
vector<int64_t> make_cumsum(const vector<Int>& v) {
    vector<int64_t> cumsum(v.size()+1);
    for (size_t i = 1; i < cumsum.size(); ++i) {
        cumsum[i] = cumsum[i-1] + v[i-1];
    }
    return cumsum;
}

// [first, last) の和を返す
inline int64_t sum_of(const vector<int64_t>& cumsum, int first, int last) noexcept {
    return cumsum[last] - cumsum[first];
}

// 区間[a, b)の中で最初に pred(x) = true となるような x を返す。
// そのような x が存在しないときは b を返す。
template <class Pred>
int64_t bin_search(int64_t a, int64_t b, Pred pred) {
    // 不変条件: i<a ⇒ pred(i)=false, i>=b ⇒ pred(i)=true
    if (a == b) return b;
    int64_t m = a + (b - a) / 2;
    if (pred(m))
        return bin_search(a, m, pred);
    else
        return bin_search(m+1, b, pred);
}

int main() {
    int N = read_int();
    int M = read_int();
    int64_t K = read_int();
    vector<int64_t> A(N), B(M);
    REP(i, N) A[i] = read_int();
    REP(i, M) B[i] = read_int();

    auto cumsum_a = make_cumsum(A);
    auto cumsum_b = make_cumsum(B);

    int64_t ans = 0;
    REP(a, N+1) {
        // 机Aの本を a 冊読むとする
        auto time_a = sum_of(cumsum_a, 0, a);
        if (time_a > K) break;
        auto max_b = bin_search(1, M+1, [&](int b) {
            auto time_b = sum_of(cumsum_b, 0, b);
            return (time_a + time_b) > K;
        });
        assign_max(ans, a + max_b - 1);
    }
    cout << ans << LF;
}
