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

using PI = P<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, n; cin >> h >> n;
    V<PI> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
    V< V<int> > dp(2, V<int>(h + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[1] = V<int>(h + 1, INF);
        for (int j = 0; j <= h; j++) {
            chmin(dp[1][j], dp[0][j]);
            chmin(dp[1][min(j + ab[i].first, h)], dp[1][j] + ab[i].second);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][h] << '\n';
    return 0;
}
