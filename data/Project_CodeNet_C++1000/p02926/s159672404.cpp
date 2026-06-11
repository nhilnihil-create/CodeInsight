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

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
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

struct engine {
    ll x, y;
    long double angle;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(30);

    ll N;
    cin >> N;
    vector<engine> engines;
    Rep (i, N) {
        ll x, y;
        cin >> x >> y;
        engines.push_back({x, y, atan2((long double) y, (long double) x)});
    }

    auto f = [](engine a, engine b) {
        return a.angle < b.angle;
    };

    sort(engines.begin(), engines.end(), f);

    // Rep (i, N) {
    //     cout << engines[i].x << " " << engines[i].y << " " << engines[i].angle << "\n";
    // }

    ll ans = 0;
    auto dist = [](ll x1, ll y1, ll x2, ll y2) {
        ll x = x1-x2;
        ll y = y1-y2;
        return x*x + y*y;
    };


    Rep (i, N) {
        ll nowx = 0;
        ll nowy = 0;
        chmax(ans, dist(nowx, nowy, 0, 0));
        for (ll j = i; j < i+N; j++) {
            nowx += engines[j%N].x;
            nowy += engines[j%N].y;
            chmax(ans, dist(nowx, nowy, 0, 0));
        }
    }

    cout << sqrt((long double) ans) << endl;
}