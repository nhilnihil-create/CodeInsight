#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

bool check(V< V<bool> > &fi) {
    bool ok = false;
    bool tate;
    for (int i = 0; i < 3; i++) {
        tate = true;
        for (int j = 0; j < 3; j++) {
            tate = tate && fi[i][j];
        }
        ok = ok || tate;
    }

    for (int i = 0; i < 3; i++) {
        tate = true;
        for (int j = 0; j < 3; j++) {
            tate = tate && fi[j][i];
        }
        ok = ok || tate;
    }

    ok = ok || (fi[0][0] && fi[1][1] && fi[2][2]);
    ok = ok || (fi[0][2] && fi[1][1] && fi[2][0]);
    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    V< V<int> > a(3, V<int>(3));
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> a[i][j];
    V< V<bool> > bingo(3, V<bool>(3, false));
    bool ans = false;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        for (int ii = 0; ii < 3; ii++) {
            for (int jj = 0; jj < 3; jj++) {
                if (a[ii][jj] == b) bingo[ii][jj] = true;
            }
        }
        ans = ans || check(bingo);
    }
    if (ans) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
