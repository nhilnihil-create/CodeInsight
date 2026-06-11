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
    
    
    int n;
    cin >> n;
    
    vector<pii> v(n);
    rep(i, n) { cin >> v[i].F; v[i].S = i; }
    
    sort(all(v), greater<pii>());
    
    // multiset<int> s;
    set<int> s;
    s.insert(-1);
    s.insert(n);
    /*
    s.insert(-1);
    s.insert(n);
    */
    s.insert(-2);
    s.insert(n + 1);
    
    ll ans = 0;
    rep(i, n) {
        auto it = s.upper_bound(v[i].S);
        auto it2 = it;
        ++it2;
        auto it3 = it;
        --it3;
        auto it4 = it3;
        --it4;
        /*
        if (*it3 != -1) ans += v[i].F * (*it - v[i].S) * (v[i].S - *it4);
        if (*it != n) ans += v[i].F * (*it2 - v[i].S) * (v[i].S - *it3);
        s.insert(v[i].S);
        
        
        {
            cout << endl << *it << " " << *it2 << " " << *it3 << " " << *it4 << endl;
            cout << (*it - v[i].S) << " " << (v[i].S - *it4) << " " << (*it2 - v[i].S) << " " << (v[i].S - *it3) << endl;
            cout << ans << endl;
        }
        */
        // cout << endl << *it << " " << *it2 << " " << *it3 << " " << *it4 << endl;
       
        if (*it3 != -1) ans += (ll)v[i].F * (*it - v[i].S) * (*it3 - *it4);
        if (*it != n) ans += (ll)v[i].F * (*it2 - *it) * (v[i].S - *it3);
        
        s.insert(v[i].S);
    }
    // rep3(i, 1, n) ans -= v[i].F; // 最初以外要素数1countしてた
    cout << ans << endl;
}
