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
class Solve {
public:

    void solve() {
        int N;
        cin >> N;
        if (N <= 2 || N == 4) {
            cout << "No" << endl;
            return;
        }

        int bsize = (N + 1) / 4 * 4 - 1;
        vector<int> base;
        for (int i = 0; i + 3 <= bsize; i += 4) {
            for (int j = 0; j < 4; ++j) {
                if (i + j > 0)
                    base.push_back(i + j);
            }
            for (int j = 0; j < 4; ++j) {
                if (i + j > 0)
                    base.push_back(i + j + N);
            }
        }

        if (N % 4 != 0) {
            for (int i = 0; i < 6; ++i) {
                base.push_back(*base.begin());
                base.erase(base.begin());
            }
        } else {
            int target = N ^(N - 1);
            if (target > N) {
                cout << "No" << endl;
                return;
            }
            for (int val = target; val >= target - 3; --val) {
                auto pt = find(all(base), val);
                base.erase(pt);
                base.push_back(val);
            }
            for (int val = target + N; val >= target - 3 + N; --val) {
                auto pt = find(all(base), val);
                base.erase(pt);
                base.push_back(val);
            }
        }

        vector<pair<int, int>> edges;
        for (int i = 0; i + 1 < base.size(); ++i) {
            edges.emplace_back(base[i], base[i + 1]);
        }

        int k = N / 4;

        if (N % 4 == 0) {
            if (__builtin_popcount(N) == 1) {
                cout << "No" << endl;
                return;
            }

            int target = N ^(N - 1);
            edges.emplace_back(2 * N - 1, 2 * N);
            edges.emplace_back(target, N);
        } else if (N % 4 != 3) {
            edges.emplace_back(1, 4 * k + 1);
            edges.emplace_back(4 * k + 1, 4 * k);
            edges.emplace_back(1, 4 * k + N);
            edges.emplace_back(4 * k + N, 4 * k + 1 + N);

            if (N % 4 == 2) {
                edges.emplace_back(2, 4 * k + 2);
                edges.emplace_back(4 * k + 1, 4 * k + 2 + N);
            }
        }

        cout << "Yes" << endl;
        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }


    }

};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
