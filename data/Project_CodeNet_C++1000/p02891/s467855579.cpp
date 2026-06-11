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
    
    string s;
    ll k;
    cin >> s >> k;
    vll a;
    rep(i, sz(s)) {
        if (i == 0) a.pb(1);
        else if (s[i-1] == s[i]) a.back()++;
        else a.pb(1);
    }
    ll ans = 0;
    if (sz(a) == 1) ans = (a[0] * k) / 2;
    else if (sz(a) == 2) ans = (a[0] / 2 + a[1] / 2) * k;
    else {
        rep(i, sz(a)) {
            if (i == 0 || i == sz(a) - 1) continue;
            ans += a[i] / 2;
        }
        ans *= k;
        if (s[0] == s.back()) {
            ans += a[0] / 2 + a.back() / 2;
            ans += (k-1) * ((a[0] + a.back()) / 2);
        } else {
            ans += (a[0] / 2 + a.back() / 2) * k;
        }
    }
    cout << ans << endl;
}