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

char read_char() {
    int ch = getchar_unlocked();
    while (isspace(ch)) { ch = getchar_unlocked(); }
    return ch;
}

string read_word() {
    string ret;
    int ch = getchar_unlocked();
    while (isspace(ch)) { ch = getchar_unlocked(); }
    for (; ch != EOF && !isspace(ch); ch = getchar_unlocked())
        ret += ch;
    ungetc(ch, stdin);
    return ret;
}

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()

template <typename T> inline void assign_min(T& x, const T& value) noexcept { x = min(x, value); }
template <typename T> inline void assign_max(T& x, const T& value) noexcept { x = max(x, value); }

constexpr char LF = '\n';

int main() {
    int N = read_int();
    string C = read_word();

    int total_w = 0, total_r = 0;
    REP(i, N) {
        if (C[i] == 'W')
            ++total_w;
        else
            ++total_r;
    }

    // 0~iをすべてRにし、i+1~N-1をWにしたい
    // max(前半のWの数, 後半のRの数)
    auto ans = min(total_w, total_r);
    int n_w = 0, n_r = 0;
    REP(i, N) {
        if (C[i] == 'W')
            ++n_w;
        else
            ++n_r;
        assign_min(ans, max(n_w, total_r - n_r));
    }
    cout << ans << LF;
}
