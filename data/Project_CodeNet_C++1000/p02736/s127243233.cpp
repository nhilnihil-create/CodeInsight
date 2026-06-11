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
    int n; string s;
    cin >> n >> s;
    V<int> a;
    for (int i = 0; i < n - 1; i++) {
        a.emplace_back(abs(s[i] - s[i + 1]));
    }
    n--;

    bool exist1 = false;
    for (int i = 0; i < n; i++) if (a[i] == 1) exist1 = true;
    // 01 だけにする
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            if (exist1) a[i] = 0;
            else a[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        int tmp = 1;
        for (int bit = 0; bit < 30; bit++) {
            int nbit = (n - 1) >> bit & 1, rbit = i >> bit & 1;
            if (nbit < rbit) tmp &= 0;
            else tmp &= 1;
        }
        ans ^= tmp;
    }
    if (!exist1) ans *= 2;
    cout << ans << '\n';
    return 0;
}
