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
    vector<ll> us(N-1);
    vector<ll> vs(N-1);
    vector<ll> right_mins(N, LL_MAX);
    vector<ll> left_maxs(N, LL_MIN);
    rep(i,0,N-1) {
        cin >> us[i] >> vs[i];
        us[i]--;
        vs[i]--;
        if (us[i] > vs[i]) {
            swap(us[i], vs[i]);
        }
        chmin(right_mins[us[i]], vs[i]);
        chmax(left_maxs[vs[i]], us[i]);
    }
    auto count_contain = [N](ll left, ll right) {
        return (left+1)*(N-right);
    };
    ll ans = 0;
    rep(i,0,N) {
        ans += count_contain(i, i);
    }
    rep(i,0,N-1) {
        ans -= count_contain(us[i], vs[i]);
    }
//    rep(i,0,N) {
//        ll connected = 0;
//        if (left_maxs[i] != LL_MIN && right_mins[i] == LL_MAX) {
//            connected = count_contain(left_maxs[i], i);
//        } else if (left_maxs[i] == LL_MIN && right_mins[i] != LL_MAX) {
//            connected = count_contain(i, right_mins[i]);
//        } else {
//            connected += count_contain(i, right_mins[i]);
//            connected += count_contain(left_maxs[i], i);
//            connected -= count_contain(left_maxs[i], right_mins[i]);
//        }
//        ll isolated = N * (N+1) / 2 - connected;
//        ans -= isolated;
//    }
    cout << ans << endl;
}
