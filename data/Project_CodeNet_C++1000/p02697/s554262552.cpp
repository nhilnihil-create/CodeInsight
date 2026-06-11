#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int X = (A); X <= (Y);++X)
#define _rep2(X, Y) for (int X = 0; X < (Y); ++X)
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X, Y) for (int X = (Y-1); X >= 0; --X)
#define all(X) (X).begin(),(X).end()
#define len(X) ((int)(X).size())
#define mod(n, m) (((n)%(m)+(m))%(m))
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N, M;

int main() {

    cin >> N >> M;

    if (M % 2 == 0) {
        rep(i, M / 2) {
            cout << i + 1 << ' ' << M + 1 - i << endl;
        }
        rep(i, M / 2) {
            cout << M + 2 + i << ' ' << 2 * M + 1 - i << endl;
        }
    } else {
        rep(i, M / 2) {
            cout << 1 + i << ' ' << M - i << endl;
        }
        rep(i, (M + 1) / 2) {
            cout << M + 1 + i << ' ' << 2 * M + 1 - i << endl;
        }
    }

    return 0;
}
