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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vll dp(n + 1, 0);
    dp[0] = 1000;

    for (int i = 1; i <= n; i++) {
        chmax(dp[i], dp[i - 1]);
        for (int j = 1; j < i; j++) {
            ll kabu =  dp[j] / a[j - 1];
            chmax(dp[i], dp[j] - (a[j - 1] * kabu) + kabu * a[i - 1]);
        }
    }
    // DEBUG_VLL(dp)
    cout << dp[n] << '\n';
    return 0;
}
