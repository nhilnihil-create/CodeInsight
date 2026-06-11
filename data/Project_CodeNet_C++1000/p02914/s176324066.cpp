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
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) ans ^= a[i];
    for (int i = 0; i < 60; i++) {
        if ((ans >> i) & 1) {
            for (int j = 0; j < n; j++) {
                a[j] &= ((1LL << 61) - 1) ^ (1LL << i);
            }
        }
    }

    int rank = 0;
    V<int> rankb;
    for (int i = 60; i >= 0; i--) {
        int j = rank;
        for (; j < n; j++) {
            if ((a[j] >> i) & 1) {
                swap(a[j], a[rank]);
                break;
            }
        }
        if (j == n) continue;
        for (j = 0; j < n; j++) {
            if (j == rank) continue;
            if ((a[j] >> i) & 1) a[j] ^= a[rank];
        }
        rankb.emplace_back(i);
        rank++;
    }

    ll ab = 0;
    for (int i = 60; i >= 0; i--) {
        // i bit 目を 0 に出来るか？
        ll tmpab = ab | (1LL << i);
        for (int j = 0; j < rank; j++) {
            if ((tmpab >> rankb[j]) & 1) tmpab ^= a[j];
        }
        if (((ab | (1LL << i)) & tmpab) == 0) ab |= (1LL << i);
    }
    cout << ans + ab * 2 << '\n';
    return 0;
}
