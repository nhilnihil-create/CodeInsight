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

ll n;
vll p;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    p.resize(n);
    vll pidx(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        pidx[p[i]] = i;
    }

    ll ans = 0;
    multiset<ll> iset;
    iset.insert(n); iset.insert(n); iset.insert(-1); iset.insert(-1);
    for (ll i = n; i >= 1; i--) {
        ll pi = pidx[i];
        auto it = iset.lower_bound(pi);
        ll r1max = *it;
        it++;
        ll r2max = *it;
        it--, it--;
        ll l1max = *it;
        it--;
        ll l2max = *it;
        ll cnt = (l1max - l2max) * (r1max - pi) + (r2max - r1max) * (pi - l1max);
        // cout << l2max << ' ' << l1max << ' ' << r1max << ' ' << r2max << '\n';
        // cout << i << ' ' << cnt << '\n';
        ans += i * cnt;
        iset.insert(pi);
    }
    cout << ans << '\n';
    return 0;
}
