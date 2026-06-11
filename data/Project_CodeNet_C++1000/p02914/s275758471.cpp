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
        Int N;
        cin >> N;
        vector<Int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        Int X = 0;
        for (int i = 0; i < N; ++i) {
            X ^= A[i];
        }

        vector<Int> B(N);
        for (int i = 0; i < N; ++i) {
            B[i] = (~X) & A[i];
        }

        int bi = 0;
        for (Int mask = (1ll << 61); mask > 0; mask >>= 1) {
            int i = bi;
            for (; i < N; ++i) {
                if (mask & B[i]) {
                    break;
                }
            }
            if (i < N) {
                swap(B[i], B[bi]);

                for (int j = 0; j < N; ++j) {
                    if (mask & B[j] && j != bi) {
                        B[j] ^= B[bi];
                    }
                }
                bi++;
            }
        }
        Int Y = 0;
        for (int i = 0; i < N; ++i) {
            Y ^= B[i];
        }

        Int ans = Y * 2 + X;

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
