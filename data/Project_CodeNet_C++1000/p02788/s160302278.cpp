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
    
    ll n, d, a;
    cin >> n >> d >> a;
    vp xh(n);
    rep(i, n) {
        int x, h;
        cin >> x >> h;
        xh[i] = P(x, h);
    }
    sort(xh.begin(), xh.end());
    
    vector<ll> range;
    vector<ll> bomb;
    bomb.pb(0);
    ll cnt = 0;
    for (auto p : xh) {
        int now_x = p.fi;
        int now_h = p.se;
        int idx = lower_bound(range.begin(), range.end(), now_x) - range.begin();
        if (idx != sz(range)) {
            now_h -= a * (bomb[sz(bomb) - 1] - bomb[idx]);
        }
        if (now_h <= 0) continue;
        bomb.pb((now_h + (a-1)) / a);
        cnt += bomb.back();
        bomb[sz(bomb) - 1] += bomb[sz(bomb) - 2];
        range.pb(now_x + 2*d);
    }
    cout << cnt << endl;
}