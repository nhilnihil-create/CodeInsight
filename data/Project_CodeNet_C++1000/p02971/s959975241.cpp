#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
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
}

int main() {
    int n; cin >> n;
    vec<int> sorted(n), a(n);
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        sorted[i] = a[i] = b;
    }
    sort(sorted.rbegin(), sorted.rend());

    for (int i = 0; i < n; ++i) {
        if (sorted[0] <= a[i]) cout << sorted[1] << endl;
        else cout << sorted[0] << endl;
    }
}

