#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
    
    int n, k;
    cin >> n >> k;

    int mx = (n-1) * (n-2) / 2;
    if (k > mx) {
        cout << -1 << endl;
        return 0;
    }
    vp ans;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (int j = i + 1; j <= n; ++j) {
            if (i != 1 && mx - cnt == k) {
                break;
                flag = true;
            }
            ans.eb(i, j);
            if (i != 1) cnt++;
        }
        if (flag) break;
    }
    cout << sz(ans) << endl;
    rep(i, sz(ans)) cout << ans[i].fi << " " << ans[i].se << endl;
}