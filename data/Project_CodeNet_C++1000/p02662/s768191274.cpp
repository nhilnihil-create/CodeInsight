#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
//i64 mod = 1000000007;
i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;

template<typename IntType>
struct mat2d_t {
    mat2d_t(size_t h, size_t w) : h(h), w(w) {
        mat = std::vector<std::vector<IntType>>(h, std::vector<IntType>(w, 0));
    }
    mat2d_t(size_t h, size_t w, IntType init) : h(h), w(w){
        mat = std::vector<std::vector<IntType>>(h, std::vector<IntType>(w, init));
    }

    std::vector<IntType>& operator[](size_t p) {
        return mat[p];
    }

    const std::vector<IntType>& operator[](size_t p) const {
        return mat[p];
    }
    size_t height() const {
        return h;
    }
    size_t width() const {
        return w;
    }

private:
    std::vector<std::vector<IntType>> mat;
    size_t h;
    size_t w;
};

int main(int argc, char **argv) {
    i64 n, s;
    cin >> n >> s;

    vector<i64> as(n);
    for (i64 i=0;i <n; ++i) {
        cin >> as[i];
    }


    mat2d_t<i64> dp(n+1, s+1, 0);
    dp[0][0] = 1;
    for (i64 i=1; i<n+1; ++i) {
        i64 a = as[i-1];
        for (i64 j=0; j<s+1; ++j) {
            dp[i][j] += dp[i-1][j] * 2;
            if (0 <= j-a && j-a < s+1)
                dp[i][j] += dp[i-1][j-a];
            dp[i][j] %= mod;
        }
    }
/*
    for (int i= 0; i<n+1; ++i) {
        for (int j=0; j<s+1; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
*/
    cout << dp[n][s] << endl;

    return 0;
}
