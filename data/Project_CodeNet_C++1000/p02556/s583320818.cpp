#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SZ(x) (int)((x).size())
#define xx first
#define yy second
#define pii pair<int, int>

const int N = 2e5 + 1;

template<typename T>
struct Vec {
    T x, y;
    Vec (T x, T y) : x(x), y(y) {}
    
    Vec<T> operator-(const Vec<T> &o) const { return Vec<T>(x - o.x, y - o.y); }
    T operator%(const Vec<T> &o) const { return x * o.y - y * o.x; }
    bool operator==(const Vec<T> &o) const { return x == o.x && y == o.y; }
    bool operator!=(const Vec<T> &o) const { return x != o.x || y != o.y; }
};

bool vectorLT(const Vec<ll>& lhs, const Vec<ll>& rhs) {
    if (lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}
struct ConvexHull {
    void removeDupes(vector<Vec<ll>> &pts) {
        sort(pts.begin(), pts.end(), vectorLT);
        pts.erase(unique(pts.begin(), pts.end()), pts.end());
    }
    
    bool right(Vec<ll> a, Vec<ll> b, Vec<ll> c) {
        return (b - a) % (c - a) > 0;
    }

    vector<Vec<ll>> getHull(vector<Vec<ll>> pts) {
        sort(pts.begin(), pts.end(), vectorLT);
        if (pts.size() < 3) return pts;
        int n = pts.size(), j = 2, k = 2;
        vector<Vec<ll>> lo(n, Vec<ll>(0, 0));
        vector<Vec<ll>> hi(n, Vec<ll>(0, 0));
        lo[0] = pts[0]; lo[1] = pts[1];
        for (int i = 2; i < n; i++) {
            Vec<ll> p = pts[i];
            while (j > 1 && !right(lo[j - 2], lo[j - 1], p)) j--;
            lo[j++] = p;
        }
        hi[0] = pts[n - 1], hi[1] = pts[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            Vec<ll> p = pts[i];
            while (k > 1 && !right(hi[k - 2], hi[k - 1], p)) k--;
            hi[k++] = p;
        }
        vector<Vec<ll>> ans;
        ans.reserve(j + k - 2);
        for (int i = 0; i < k; i++) ans.push_back(hi[i]);
        for (int i = 1; i < j - 1; i++) ans.push_back(lo[i]);
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<Vec<ll>> pts;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
    }

    ConvexHull ch;
    ch.removeDupes(pts);
    vector<Vec<ll>> hull = ch.getHull(pts);
    int m = SZ(hull);

    auto dist = [&](Vec<ll> u, Vec<ll> v) {
        return abs(u.x - v.x) + abs(u.y - v.y);
    };

    ll ans = 0;
    for (int i = 0, j = 1 % m; i < m; i++) {
        ll cur = dist(hull[i], hull[j]);
        while (i != j && dist(hull[i], hull[(j + 1) % m]) >= cur) {
            ans = max(ans, cur);
            j = (j + 1) % m;
            cur = dist(hull[i], hull[j]);
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
