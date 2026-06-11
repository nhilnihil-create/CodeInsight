#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cmath>
#include <climits>
#include <cstdint>
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

    constexpr int64_t mpow(int64_t a, int64_t b, int64_t mod = 1000000007) {
        if (b <= 0) return 1; if (b == 1) return a % mod; if (b == 2) return (a * a) % mod;
        return (max(a * (b & 1), (int64_t)1) * mpow(mpow(a, b / 2, mod), 2, mod)) % mod;
    }
    constexpr int64_t mdiv(int64_t a, int64_t b, int64_t mod = 1000000007) {
        return (a * mpow(b, mod - 2, mod)) % mod;
    }
}

int main() {
    int64_t n; cin >> n;
    cout << (n * (n - 1)) / 2 << endl;
}

