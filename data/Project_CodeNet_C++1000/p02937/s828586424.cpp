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
    
    string s, t;
    cin >> s >> t;
    ll n = sz(s);
    vvi cnt(26);
    rep(i, n) {
        cnt[s[i]-'a'].pb(i);
    }
    ll now = -1;
    ll m = sz(t);
    rep(i, m) {
        int idx = t[i] - 'a';
        if (sz(cnt[idx]) == 0) {
            cout << -1 << endl;
            return 0;
        }
        int x = upper_bound(cnt[idx].begin(), cnt[idx].end(), now%n) - cnt[idx].begin();
        if (x == sz(cnt[idx])) {
            now = (now + n) / n * n + cnt[idx][0];
        } else {
            now = now / n * n + cnt[idx][x];
        }
    }
    cout << now+1 << endl;
}
