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
    int bingo[3][3];
    for (auto &e1 : bingo) for (auto &e2 : e1) cin >> e2;
    int n; cin >> n;

    bool hole[3][3];
    for (auto &e1 : hole) for (auto &e2 : e1) e2 = false;

    while (n--) {
        int b; cin >> b;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (bingo[i][j] == b) {
                    hole[i][j] = true;
                }
            }
        }
    }

    cout << (
        (hole[0][0] && hole[0][1] && hole[0][2]) ||
        (hole[1][0] && hole[1][1] && hole[1][2]) ||
        (hole[2][0] && hole[2][1] && hole[2][2]) ||
        (hole[0][0] && hole[1][0] && hole[2][0]) ||
        (hole[0][1] && hole[1][1] && hole[2][1]) ||
        (hole[0][2] && hole[1][2] && hole[2][2]) ||
        (hole[0][0] && hole[1][1] && hole[2][2]) ||
        (hole[0][2] && hole[1][1] && hole[2][0])
        ? "Yes" : "No"
    ) << endl;
}

