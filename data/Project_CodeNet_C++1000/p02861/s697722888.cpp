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

double solver(vec<int> &visited, vec<array<int, 2>> &coord, int depth = 0) {
    double sum = 0;

    if (depth == visited.size()) {
        for (int i = 1; i < visited.size(); ++i) {
            int p1 = visited[i - 1], p2 = visited[i];
            sum += sqrt(pow(coord[p1][0] - coord[p2][0], 2) + pow(coord[p1][1] - coord[p2][1], 2));
        }
        return sum;
    }

    for (int i = 0; i < visited.size(); ++i) {
        if (visited[i] != -1) continue;
        visited[i] = depth;
        sum += solver(visited, coord, depth + 1);
        visited[i] = -1;
    }
    return sum;
}

int main() {
    cout << fixed;

    int n; cin >> n;
    vec<array<int, 2>> coord(n);
    for (auto &e : coord) cin >> e[0] >> e[1];

    int fact = 1;
    for (int i = 2; i <= n; ++i) fact *= i;

    vec<int> visited(n, -1);
    cout << solver(visited, coord) / fact << endl;
}

