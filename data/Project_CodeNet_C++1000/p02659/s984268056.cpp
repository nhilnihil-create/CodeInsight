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

string read_word() {
    string ret;
    int ch = getchar_unlocked();
    while (isspace(ch)) { ch = getchar_unlocked(); }
    for (; ch != EOF && !isspace(ch); ch = getchar_unlocked())
        ret += ch;
    ungetc(ch, stdin);
    return ret;
}

using int128 = __int128_t;

int main() {
    int128 A = read_int();
    string B = read_word();

    int128 C = 0;
    REP(i, B.size()) {
        if (B[i] == '.') continue;
        C = (C * 10) + (B[i] - '0');
    }
    cout << int64_t(A*C/100) << endl;
}
