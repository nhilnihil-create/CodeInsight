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
    sort(a.begin(), a.end());
    vp ans;
    if (a[0] <= 0) {
        for (int i = 1; i < n-1; ++i) {
            if (a[i] <= 0) {
                ans.eb(a[n-1], a[i]);
                a[n-1] -= a[i];
            } else {
                ans.eb(a[0], a[i]);
                a[0] -= a[i];
            }
        }
        ans.eb(a[n-1], a[0]);
        a[n-1] -= a[0]; 
    } else {
        for (int i = 1; i < n-1; ++i) {
            ans.eb(a[0], a[i]);
            a[0] -= a[i];
        }
        ans.eb(a[n-1], a[0]);
        a[n-1] -= a[0];
    }
    cout << a[n-1] << endl;
    rep(i, n-1) {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
}