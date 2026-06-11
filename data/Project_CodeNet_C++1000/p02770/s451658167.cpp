//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
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

int main() {
    ll K, Q;
    cin >> K >> Q;
    vector<ll> Ds(K);
    rep(i,0,K) {
        cin >> Ds[i];
    }
    rep(q,0,Q) {
        ll N, X, M;
        cin >> N >> X >> M;
        vector<ll> mod_ds(K);
        rep(k,0,K) {
            mod_ds[k] = Ds[k] % M;
            if (mod_ds[k] == 0) {
                mod_ds[k] = M;
            }
        }
        ll inc = 0;
        ll sum = 0;
        rep(i,0,K) {
            if ((N-1) % K == i) {
                inc += sum;
            }
            sum += mod_ds[i];
        }
        inc += (N-1)/K * sum;
        X = X % M;
        ll dec_cnt;
        if (inc < M - X) {
            dec_cnt = 0;
        } else {
            inc -= (M - X);
            dec_cnt = 1 + inc/M;
        }
        cout << N - 1 - dec_cnt << endl;
    }
}
