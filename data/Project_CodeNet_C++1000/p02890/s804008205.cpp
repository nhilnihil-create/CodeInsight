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
        vector<Int> C(N + 1);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            C[A[i]]++;
        }

        sort(all(C));

        Int sum = 0;
        int idx = 0;
        vector<Int> anss(N + 1);
        for (int k = 1; k <= N; ++k) {
            while (idx <= N && C[idx] < k) {
                sum += C[idx];
                idx++;
            }
            Int pre = sum;
            Int suf = (N - idx + 1) * k;
            Int val = pre + suf;
            Int K = val / k;
            anss[K] = k;
        }
        for (int K = N; K > 0; --K) {
            chmax(anss[K - 1], anss[K]);
        }

        for (int i = 1; i <= N; ++i) {
            cout << anss[i] << endl;
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
