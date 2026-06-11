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
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    V<int> a(n);
    V<int> cnta(300001, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnta[a[i]]++;
    }
    
    V<int> aaa;
    for (int i = 1; i < 300001; i++) {
        if (cnta[i] == 0) continue;;
        aaa.emplace_back(cnta[i]);
    }
    sort(ALL(aaa));

    // f[i]: i 個の列を取り出す時に出せる最大長
    V<int> f(n + 2, 0);
    int rem = n;
    int over = 0;
    for (int i = n; i >= 1; i--) {
        while (!aaa.empty() && aaa.back() > i) {
            over++;
            rem -= aaa.back();
            aaa.pop_back();
        }
        f[i] = (rem + over * i) / i;
    }
    // DEBUG_VLL(f)

    for (int k = 1; k <= n; k++) {
        int low = 1, high = n + 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (k <= f[mid]) low = mid + 1;
            else high = mid;
        }
        cout << low - 1 << '\n';
    }
    return 0;
}
