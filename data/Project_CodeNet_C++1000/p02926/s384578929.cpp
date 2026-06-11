#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

struct Point {
    int x, y;
    double angle;
    bool operator<(const Point &p) {
        return angle < p.angle;
    }
};

int main() {
    FAST_IO();
    int N; cin >> N;
    vector<Point> v(N);
    rep(i, N) {
        cin >> v[i].x >> v[i].y;
        v[i].angle = atan2(v[i].y, v[i].x);
    }
    sort(all(v));
    ll cx = 0, cy = 0;
    ll ans = 0;
    rep(i, N) {
        cx = cy = 0;
        rep(k, N) {
            int j = (i + k) % N;
            cx += v[j].x;
            cy += v[j].y;
            ans = max(ans, cx * cx + cy * cy);
        }
    }
    cout.precision(12);
    cout << sqrt(ans) << "\n";
}