#include <algorithm>
#include <array>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct Point {
    Point(ll x, ll y, ll id) : x(x), y(y), id(id) {}
    Point() : Point(0, 0, 0) {}
    void read(ll i) { id = i; cin >> x >> y; }
    ll x, y, id;
    Point operator+=(const Point& other) { x += other.x; y += other.y; return *this; }
    Point operator+(const Point& other) { Point ans = *this; return ans += other; }
    Point operator-=(const Point& other) { x -= other.x; y -= other.y; return *this; }
    Point operator-(const Point& other) { Point ans = *this; return ans -= other; }
    ll norm2() const { return x * x + y * y; }

    int type() const {
        return x < 0 || (x <= 0 && y < 0);
    }
};

bool operator<(const Point &a, const Point &b) {
    if (a.type() != b.type()) {
        return a.type() < b.type();
    }
    ll cp = a.x * b.y - a.y * b.x;;
    if (abs(cp) > 0) {
        return cp > 0;
    }
    return a.id < b.id;
}

int main() {
    cout << setprecision(30);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    vector<Point> ps(n);
    Point sum;
    for (ll i = 0; i < n; ++i) {
        ps[i].read(i);
        sum += ps[i];
    }
    sort(ps.begin(), ps.end());
    ll ans = 0;
    for (ll l = 0; l < n; ++l) {
        for (ll r = l; r <= n; ++r) {
            Point p;
            for (ll i = l; i < r; ++i) {
                p += ps[i];
            }
            ans = max(ans, p.norm2());
            ans = max(ans, (sum - p).norm2());
        }
    }
    cout << sqrt(ans) << endl;

    return 0;
}
