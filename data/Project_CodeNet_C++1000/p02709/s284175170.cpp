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
i64 mod = 1000000007;
int int_max = 2147483647;
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
    int n;
    cin >> n;

    std::multimap<i64, int, std::greater<i64>> as;
    for (int i=0; i<n; ++i) {
        i64 a;
        cin >> a;
        as.insert(make_pair(a, i+1));
    }
    mat2d_t<i64> dp(n+1, n+1, 0);

    i64 ans{0};

    auto it = as.begin();
    for (int i=1; i<n+1; ++i, ++it) {
       int idx = it->second;
       i64 a = it->first;

       if (i==1) {
           dp[i][0] = a * abs(n-idx);
           dp[i][1] = a * abs(idx-1);
           continue;
       }

       for (int j=0; j<=i; ++j) {
           if (j == 0)
               dp[i][0] = dp[i-1][0] + a*abs(n-(i-1-j)-idx);
           else
               dp[i][j] = max(dp[i-1][j] + a*abs(n-(i-1-j)-idx),
                          dp[i-1][j-1] + a*abs(idx-j));
           //cout << "i:" << i << " j:" <<j << " dp:" << dp[i][j] << endl;
           ans = max(ans,dp[i][j]);
       }
    }

    cout << ans <<endl;

    return 0;
}
