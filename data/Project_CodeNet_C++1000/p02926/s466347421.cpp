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

//改造
typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
#define MAX_X 100000001
//#define MAX_X 100001

class Solve {
public:
    int N = 0;
    vector<Int> X, Y;


    void solve() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Int x, y;
            cin >> x >> y;
            if (x != 0 || y != 0) {
                X.push_back(x);
                Y.push_back(y);
                N++;
            }
        }


        double ans = 0.0;

        vector<int> idxes(N);
        for (int i = 0; i < N; ++i) {
            idxes[i] = i;
        }

        sort(all(idxes), [&](int a, int b) {
            double A = atan2(Y[a], X[a]);
            double B = atan2(Y[b], X[b]);

            return A < B;
        });

//        for (int l = 0; l <= N; ++l) {
//            for (int r = 0; r <= N; ++r) {
//                Int x1 = 0;
//                Int y1 = 0;
//                Int x2 = 0;
//                Int y2 = 0;
//
//                for (int i = 0; i < N; ++i) {
//                    if (i >= l && i < r) {
//                        x1 += X[idxes[i]];
//                        y1 += Y[idxes[i]];
//                    } else {
//                        x2 += X[idxes[i]];
//                        y2 += Y[idxes[i]];
//                    }
//                }
//
//                Int tmp = max(x1 * x1 + y1 * y1, x2 * x2 + y2 * y2);
//                chmax(ans, sqrt(tmp));
//            }
//        }

        rep(_, 0, N) {
            Int x = 0;
            Int y = 0;

            for (int i = 0; i < N; ++i) {
                x += X[idxes[i]];
                y += Y[idxes[i]];

                chmax(ans, sqrt(x * x + y * y));
            }

            idxes.push_back(idxes[0]);
            idxes.erase(idxes.begin());
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
