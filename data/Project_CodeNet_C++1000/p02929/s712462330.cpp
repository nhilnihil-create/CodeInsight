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
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int main() {
    
    
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    for (int i = 0; i < 2 * n; i += 2) {
        str[i] = (str[i] == 'W' ? 'B' : 'W');
    }
    
    rep(i, 2 * n) {
        str[i] = (str[i] == 'W' ? 'L' : 'R');
    }
    // cout << str << endl;
    
    {
        int cnt = 0;
        rep(i, 2 * n) {
            if (str[i] == 'L') cnt++;
        }
        if (cnt != n) {
            cout << 0 << endl;
            return 0;
        }
    }
    
    ll ans = 1;
    {
        int cnt_l = 0;
        rep(i, 2 * n) {
            if (str[i] == 'L') cnt_l++;
            else {
                (ans *= cnt_l) %= inf;
                cnt_l--;
            }
        }
        rep3(i, 1, n + 1) (ans *= i) %= inf;
    }
    cout << ans << endl;
}

