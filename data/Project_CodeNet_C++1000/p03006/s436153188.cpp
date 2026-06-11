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
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

struct P {
    ll x;
    ll y;
    bool operator==(const P& rhs) const { return x == rhs.x && y == rhs.y; }
    P operator+(P rhs) { return {x + rhs.x, y + rhs.y}; }
    P operator-(P rhs) { return {x - rhs.x, y - rhs.y}; }
    P operator-() { return {-x, -y}; }
    ll operator*(P rhs) { return x * rhs.x + y * rhs.y; }
    P operator*(ll k) { return {x * k, y * k}; }
    P operator/(ll k) { return {x / k, y / k}; }
    ll len_sq() { return (*this) * (*this); }
    ll len() { return sqrt(len_sq()); }
};

namespace std {
    template<>
    struct hash<P> {
        size_t operator()(P key) const {
            char buf[16];
            memcpy(buf, &key.x, 8);
            memcpy(buf + 8, &key.y, 8);
            return hash<string>()(buf);
        }
    };
}

int main() {
    ll N;
    cin >> N;
    vector<P> pts(N);
    rep(i,0,N) {
        cin >> pts[i].x >> pts[i].y;
    }
    unordered_map<P, ll> cnt;
    rep(i,0,N) {
        rep(j,0,N) {
            if (i == j) {
                continue;
            }
            P diff = pts[i] - pts[j];
            cnt[diff]++;
        }
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll max_cnt = numeric_limits<ll>::min();
    for (auto& kv : cnt) {
        max_cnt = max(max_cnt, kv.second);
    }
    cout << N - max_cnt << endl;
}
