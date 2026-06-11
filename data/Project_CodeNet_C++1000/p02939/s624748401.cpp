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
    string s; cin >> s;
    int n = s.size();
    V< V<int> > dp(n + 1, V<int>(3, 0));
    dp[1][1] = dp[2][2] = 1;
    for (int i = 1; i < n; i++) {
        for (int pre = 1; pre <= 2; pre++) {
            if (i - pre < 0) continue;
            string pres = s.substr(i - pre, pre);
            for (int nxt = 1; nxt <= 2; nxt++) {
                if (i + nxt > n) continue;
                string nxts = s.substr(i, nxt);
                if (pres == nxts) continue;
                chmax(dp[i + nxt][nxt], dp[i][pre] + 1);
            }
        }
    }
    cout << max(dp[n][1], dp[n][2]) << '\n';
    return 0;
}
