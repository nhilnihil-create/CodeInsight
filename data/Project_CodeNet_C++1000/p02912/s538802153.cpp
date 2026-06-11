#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
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
    int n, m; cin >> n >> m;
    priority_queue<int> que;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        que.push(a);
        sum += a;
    }
    for (int i = 0; i < m; ++i) {
        int a = que.top(); que.pop();
        sum -= a;
        a /= 2;
        sum += a;
        que.push(a);
    }
    cout << sum << endl;
}

