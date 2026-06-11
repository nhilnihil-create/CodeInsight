//
// main.cpp
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
    bool operator==(const P& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

template<>
struct hash<P> {
    // ハッシュを計算する
    size_t operator()(P key) const {
        char buf[16];
        memcpy(buf, &key.x, 8);
        memcpy(buf + 8, &key.y, 8);
        return hash<string>()(buf);
    }
};

vector<P> upper_closure(vector<P> pts) {
    sort(pts.begin(), pts.end(), [](P lhs, P rhs){ return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y); });
    vector<P> upper;
    upper.push_back(pts[0]);
    rep(i,1,pts.size()) {
        while (true) {
            if (upper.size() < 2) {
                break;
            }
            P now = pts[i];
            P top = upper.back();
            P prv = *(upper.end()-2);
            if (now.x == top.x) {
                if (prv.x == top.x) {
                    break;
                }
            } else {
                if (prv.x == top.x) {
                    break;
                }
                if ((top.y - prv.y) * (now.x - top.x) > (now.y - top.y) * (top.x - prv.x)) {
                    break;
                }
            }
            upper.pop_back();
        }
        upper.push_back(pts[i]);
    }
    return upper;
}

vector<P> closure(vector<P> pts) {
    if (pts.size() == 1) {
        return pts;
    }
    vector<P> upper = upper_closure(pts);
    rep(i,0,pts.size()) {
        pts[i].x *= -1;
        pts[i].y *= -1;
    }
    vector<P> lower = upper_closure(move(pts));
    rep(i,0,lower.size()) {
        lower[i].x *= -1;
        lower[i].y *= -1;
    }
    upper.pop_back();
    lower.pop_back();
    if (lower.size() > upper.size()) {
        swap(lower, upper);
    }
    copy(lower.begin(), lower.end(), back_inserter(upper));
    return upper;
}

int main() {
    ll N;
    cin >> N;
    vector<P> vecs(N);
    rep(i,0,N) {
        cin >> vecs[i].x >> vecs[i].y;
    }
    vector<P> pts;
    pts.push_back(P{0, 0});
    rep(i,0,N) {
        P vec = vecs[i];
        unordered_set<P> new_pts(pts.begin(), pts.end());
        for (P pt : pts) {
            new_pts.insert(P{pt.x + vec.x, pt.y + vec.y});
        }
        pts = vector<P>(new_pts.begin(), new_pts.end());
        pts = closure(pts);
    }
    double ans = 0.0;
    for (P pt : pts) {
        double ans_loc = sqrt((double)pt.x * (double)pt.x + (double)pt.y * (double)pt.y);
        ans = max(ans, ans_loc);
    }
    cout << fixed << setprecision(15) << ans << endl;
}

