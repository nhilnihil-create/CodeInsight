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
#define INF (ll)(1e18)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    ll t[2];
    rep(i, 2) cin >> t[i];
    ll a[2], b[2];
    rep(i, 2) cin >> a[i];
    rep(i, 2) cin >> b[i];
    
    // youtube解説
    
    rep(i, 2) {
        a[i] *= t[i];
        b[i] *= t[i];
    }
    
    if (a[0] + a[1] == b[0] + b[1]) {
        cout << "infinity" << endl;
        return 0;
    }
    
    if (a[0] + a[1] < b[0] + b[1]) {
        swap(a[0], b[0]);
        swap(a[1], b[1]);
    }
    
    if (a[0] > b[0]) {
        cout << 0 << endl;
        return 0;
    }
    
    ll c = a[0] - b[0];
    ll d = (a[0] + a[1]) - (b[0] + b[1]);
    c = -c;
    
    if (c % d == 0) {
        cout << c / d * 2 << endl;
    } else {
        cout << c / d * 2 + 1 << endl;
    }
}

/*
 1 1
 2 6
 4 2
 
 2
 
 */
