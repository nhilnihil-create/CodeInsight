//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

[[maybe_unused]] constexpr ll LL_MAX = numeric_limits<ll>::max();
[[maybe_unused]] constexpr ll LL_MIN = numeric_limits<ll>::min();
[[maybe_unused]] constexpr ull ULL_MAX = numeric_limits<ull>::max();

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

template <typename T>
void chmin(T& x, T y) {
    x = min(x, y);
}

template <typename T>
void chmax(T& x, T y) {
    x = max(x, y);
}

ll csum(ll x, ll y) {
    if (x > 0 && y > 0 && x > LL_MAX - y) {
        return LL_MAX;
    }
    if (x < 0 && y < 0 && x < LL_MIN - y) {
        return LL_MIN;
    }
    return x + y;
}

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

int main() {
    ll N;
    cin >> N;
    vector<ll> smalls(N);
    vector<ll> larges(N);
    rep(i,0,N) {
        cin >> smalls[i] >> larges[i];
    }
    sort(smalls.begin(), smalls.end());
    sort(larges.begin(), larges.end());
    ll small = 0;
    ll large = 0;
    if (N % 2 == 0) {
        small = smalls[N/2] + smalls[N/2-1];
        large = larges[N/2] + larges[N/2-1];
    } else {
        small = smalls[N/2];
        large = larges[N/2];
    }
    cout << large - small + 1 << endl;
}
