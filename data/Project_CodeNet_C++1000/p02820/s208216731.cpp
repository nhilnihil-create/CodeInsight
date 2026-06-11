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
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;
    string t; cin >> t;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        V< V<int> > dp(2, V<int>(3, 0));
        dp[0][0] = (t[i] == 's' ? r : 0);
        dp[0][1] = (t[i] == 'p' ? s : 0);
        dp[0][2] = (t[i] == 'r' ? p : 0); 
        for (int j = i + k; j < n; j += k) {
            dp[1] = V<int>(3, 0);
            dp[1][0] = max(dp[0][1], dp[0][2]) + (t[j] == 's' ? r : 0);
            dp[1][1] = max(dp[0][0], dp[0][2]) + (t[j] == 'p' ? s : 0);
            dp[1][2] = max(dp[0][0], dp[0][1]) + (t[j] == 'r' ? p : 0);
            swap(dp[0], dp[1]);
        }
        ans += max({dp[0][0], dp[0][1], dp[0][2]});
    }
    cout << ans << '\n';
    return 0;
}
