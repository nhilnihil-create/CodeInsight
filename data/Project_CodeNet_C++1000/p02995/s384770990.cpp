#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
#include <numeric>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    int64_t e = lcm(c, d);

    auto nc = b / c - (a - 1) / c;
    auto nd = b / d - (a - 1) / d;
    auto ne = b / e - (a - 1) / e;

    cout << ((b - a + 1) - (nc + nd - ne)) << endl;
}

