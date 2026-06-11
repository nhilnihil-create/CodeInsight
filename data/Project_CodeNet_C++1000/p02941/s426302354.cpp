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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> b[i];
        if (b[i] < a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    priority_queue<pii> q;
    rep(i, n) q.push(pii(b[i], i));
    
    ll cnt = 0;
    while (!q.empty()) {
        int t = q.top().F;
        int id = q.top().S;
        q.pop();
        
        if (t == a[id]) {
            continue;
        } else if (t < a[id]) {
            cout << -1 << endl;
            return 0;
        }
        
        ll neig = (b[(id - 1 + n) % n] + b[(id + 1) % n]);
        if (b[id] % neig >= a[id]) {
            cnt += b[id] / neig;
            b[id] %= neig;
            if (b[id] == t) continue;
        } else { // a[id]まで下げていい
            cnt += (b[id] - a[id]) / (b[(id - 1 + n) % n] + b[(id + 1) % n]);
            b[id] = a[id];
            continue;
        }
        
        q.push(pii(b[id], id));
    }
    
    if (a == b) cout << cnt << endl;
    else cout << -1 << endl;
}


