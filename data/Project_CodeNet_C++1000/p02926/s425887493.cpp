#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

double atan(int a, int b) {
    if (a == 0) return (b > 0 ? M_PI / 2 : -M_PI / 2);
    if (b == 0 && a < 0) return M_PI;
    if (a < 0 && b < 0) return atan((double)b / a) - M_PI;
    if (a < 0 && b > 0) return atan((double)b / a) + M_PI;
    return atan((double)b / a);
}

bool comp(pii a, pii b) {
    return atan(a.F, a.S) < atan(b.F, b.S);
}

int main() {
    int n;
    cin >> n;
    
    vector<pii> v;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) continue;
        v.eb(pii(x, y));
    }
    
    double ans = 0;
    
    sort(all(v), comp);
    
    // cout << '\n'; rep(i, sz(v)) cout << v[i].F << " " << v[i].S << " " << atan(v[i].F, v[i].S) << '\n';
    
    
    rep(i, sz(v)) rep3(j, i, sz(v)) {
        int x = 0, y = 0;
        rep3(k, i, j + 1) {
            x += v[k].F;
            y += v[k].S;
        }
        chmax(ans, sqrt((double)x * x + (double)y * y));
    }
    
    
    // 逆方向に延ばす
    rep(i, sz(v)) {
        int x = 0, y = 0;
        rep(j, sz(v)) {
            int k = (i - j + sz(v)) % sz(v);
            x += v[k].F;
            y += v[k].S;
            chmax(ans, sqrt((double)x * x + (double)y * y));
        }
        
    }
    
    
    cout << fixed << setprecision(11) << ans << '\n';
}
