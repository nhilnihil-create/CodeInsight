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

ll N;
map<ll, ll> S;

int main() {
    cin >> N;
    rep(i,0,1<<N) {
        ll s;
        cin >> s;
        S[s]++;
    }
    if (prev(S.end())->second >= 2) {
        cout << "No" << endl;
        return 0;
    }
    priority_queue<ll> queue;
    queue.push(N);
    for (auto it = next(S.rbegin()); it != S.rend(); ++it) {
        ll count = it->second;
        vector<ll> generated;
        rep(i,0,count) {
            if (queue.empty()) {
                cout << "No" << endl;
                return 0;
            }
            ll top = queue.top();
            queue.pop();
            if (top == 0) {
                cout << "No" << endl;
                return 0;
            }
            queue.push(top-1);
            generated.push_back(top-1);
        }
        for (ll life : generated) {
            queue.push(life);
        }
    }
    cout << "Yes" << endl;
}
