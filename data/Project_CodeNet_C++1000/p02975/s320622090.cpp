#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <stack>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 998244353;
// 0~3までは右下左上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, 1, 0, -1, -1, 1, 1, -1 };

namespace {
    template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
    template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

    void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; ++i) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

    // 標準入出力
    struct inp {
        std::size_t szi, szj;
        inp(std::size_t _szi = 1, std::size_t _szj = 1) : szi(_szi), szj(_szj) {}
        template <typename T> operator T () const { T a; std::cin >> a; return a; }
        template <typename T> operator std::vector<T>() const { std::vector<T> a(szi); for (std::size_t i = 0; i < szi; ++i) std::cin >> a[i]; return a; }
        template <typename T> operator std::vector<std::vector<T>>() const {
            std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
            for (std::size_t i = 0; i < szi; ++i) for (std::size_t j = 0; j < szj; ++j) cin >> a[i][j]; return a;
        }
    };
    inp inp1;

    bool used[11][11][11][11][11];

    bool dfs(int a, int b, int c, int d, int e) {
        if (used[a][b][c][d][e]) return false;
        used[a][b][c][d][e] = true;

        bool ok = true;
        //ok &= ((d ^ b) == a);
        //ok &= ((a ^ c) == b);
        //ok &= ((b ^ d) == c);
        //ok &= ((c ^ a) == d);

        //ok &= ((c ^ b) == a);
        //ok &= ((a ^ c) == b);
        //ok &= ((a ^ b) == c);

        ok &= ((e ^ b) == a);
        ok &= ((a ^ c) == b);
        ok &= ((b ^ d) == c);
        ok &= ((c ^ e) == d);
        ok &= ((d ^ a) == e);

        if (ok) cout << a << " " << b << " " << c << " " << d << " " << e << endl;

        if (a < 6) dfs(a + 1, b, c, d, e);
        if (b < 6) dfs(a, b + 1, c, d, e);
        if (c < 6) dfs(a, b, c + 1, d, e);
        if (d < 6) dfs(a, b, c, d + 1, e);
        if (e < 6) dfs(a, b, c, d, e + 1);
    
        return true;
    }
}

int main() {

    int n = inp1;
    vector<int> a = inp(n);

    //dfs(0, 0, 0, 0, 0);

    bool can = false;
    if (accumulate(allof(a), 0) == 0) can = true;
    
    sort(allof(a));

    vector<pair<int, int>> v;
    int prev = a[0];
    v.emplace_back(prev, 0);
    rep(i, n) {
        if (a[i] == prev) {
            ++v.back().second;
        }
        else {
            prev = a[i];
            v.emplace_back(prev, 1);
        }
    }
    if (v.size() == 2) {
        if (v[0].first == 0 && v[0].second == n / 3) can = true;
    }
    else if (v.size() == 3) {
        if (v[0].second == v[1].second && v[1].second == v[2].second && 
            (v[0].first ^ v[1].first) == v[2].first && 
            (v[1].first ^ v[2].first) == v[0].first && 
            (v[0].first ^ v[2].first) == v[1].first) can = true;
    }

    Cout(Yes(can));

    return 0;
}
