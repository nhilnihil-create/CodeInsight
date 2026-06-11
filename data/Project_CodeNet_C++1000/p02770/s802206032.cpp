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
    int k, q; cin >> k >> q;
    V<int> d(k);
    for (int i = 0; i < k; i++) cin >> d[i];
    while (q-->0) {
        int n, m; ll x;
        cin >> n >> x >> m;
        x %= m;
        vll drem(k);
        V<int> cnt0(k, 0);
        for (int i = 0; i < k; i++) {
            drem[i] = (ll)(d[i] % m);
            if (drem[i] == 0) cnt0[i] = 1;
        }

        ll totald = accumulate(ALL(drem), 0LL);
        ll total0 = accumulate(ALL(cnt0), 0LL);
        totald *= (ll)((n - 1) / k);
        total0 *= (ll)((n - 1) / k);
        for (int i = 0; i < (n - 1) % k; i++) totald += drem[i], total0 += cnt0[i];
        ll lt = (totald + x) / m;
        cout << n - lt - total0 - 1 << '\n';
    }
    return 0;
}
