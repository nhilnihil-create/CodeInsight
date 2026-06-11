#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>
#include <bitset>
#include <sstream>
#include <cassert>
#include <time.h>
#include <atcoder/all>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
using namespace atcoder;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}
void printvec (vec &v) {
    Rep (i, (ll)v.size()) {
        cout << v[i] << " \n"[i+1 == (ll)v.size()];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;

    dsu d(N);

    while (Q--) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << d.same(u, v) << "\n";
        } else {
            d.merge(u, v);
        }
    }
}