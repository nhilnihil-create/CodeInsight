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
    ll N;
    cin >> N;
    ll M = (N % 2 == 0) ? N : (N + 1);
    auto ans = make_vec_nd((ll)0, M, M);
    rep(i,0,M) {
        rep(j,i+1,M) {
            ll level = 1;
            ll k = j - i;
            while (k % 2 == 0) {
                k /= 2;
                level++;
            }
            ans[i][j] = level;
        }
    }
    rep(i,0,N-1) {
        rep(j,i+1,N) {
            cout << ans[i][j];
            if (j != N-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
