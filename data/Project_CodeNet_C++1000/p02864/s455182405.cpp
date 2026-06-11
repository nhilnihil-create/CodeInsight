#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    void solve() {
        Int N, K;
        cin >> N >> K;

        vector<Int> H(N + 1);
        for (int i = 1; i <= N; ++i) cin >> H[i];

        vector<vector<Int>> dp(N + 1, vector<Int>(N + 1, INFl));
        dp[0][0] = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= N; ++j) {
                for (int k = 1; i + k <= N && j + k - 1 <= N; ++k) {
                    Int ni = i + k;
                    Int nj = j + k - 1;
                    Int nv = dp[i][j] + max(H[i + k] - H[i], 0ll);
                    chmin(dp[ni][nj], nv);
                }
            }
        }

//        Int ans = min(dp[N][K], dp[N - 1][K - 1]);
        Int ans = dp[N][K];
//        if (K > 0) chmin(ans, dp[N - 1][K - 1]);
        for (int i = 0; i <= N && i <= K; ++i) {
            Int tmp = dp[N - i][K - i];
            chmin(ans, tmp);
        }
        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
