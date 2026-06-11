#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

inline namespace atcoder {
    using i32 = int32_t; using u32 = uint32_t;
    using i64 = int64_t; using u64 = uint64_t;
    using f32 = float; using f64 = double;

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
    int n; cin >> n;
    cout << (n + 1) / 2 << endl;
}

