#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n) mp[a[i]]++;
    bool ans = false;
    if (sz(mp) == 1 && a[0] == 0) {
        ans = true;
    } else if (n%3 == 0 && sz(mp) == 2) { 
        for (auto p : mp) if (p.fi == 0 && p.se == n/3) ans = true;
    } else if (n%3 == 0 && sz(mp) == 3) {
        vp x;
        for (auto p : mp) x.eb(p.fi, p.se);
        if ((x[0].fi^x[1].fi^x[2].fi) == 0 && x[0].se == n/3 && x[1].se == n/3) ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
}