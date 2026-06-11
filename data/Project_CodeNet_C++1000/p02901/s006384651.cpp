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
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
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
    i64 n, m;
    cin >> n >> m;

    i64 up_n = (1<<n);
    mat2d_t<i64> dp(m+1, up_n, -1);

    vector<i64> as(m);
    vector<i64> bs(m, 0);

    for (int i=0; i<m; ++i) {
        i64 b;
        cin >> as[i] >> b;
        i64 c{0};
        for (int j=0; j<b; ++j) {
            cin >> c;
            --c;
            bs[i] += (1<<c);
        }
    }
    dp[0][0] = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<up_n; ++j) {
            if (dp[i][j] == -1) continue;

            if (dp[i+1][j] == -1) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            i64 next = j | bs[i];
            //cout << next << endl;

            if (next < 0 || up_n <= next) continue;

            if (dp[i+1][next] == -1) dp[i+1][next] = dp[i][j] + as[i];
            else dp[i+1][next] = min(dp[i+1][next], dp[i][j] + as[i]);
        }
    }
/*
    for (int i=0; i<m+1; ++i) {
        for (int j=0; j<up_n; ++j) {
            cout <<" "<< dp[i][j];
        }
        cout << endl;
    }

*/
    cout << dp[m][up_n-1] << endl;

    return 0;
}