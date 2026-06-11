#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
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
    ll n = s.size();
    vector<pair<char, ll>> cnt;
    cnt.emplace_back(s[0], 0);
    rep(i, n) {
        if (s[i] == cnt.back().first) cnt.back().second++;
        else cnt.emplace_back(s[i], 1);
    }
    int m = cnt.size();
    ll ans = 0;
    if (m == 1) ans = (k*n)/2;
    else {
        rep(i, m) {
            ans += k * (cnt[i].second/2);
        }
        if (s[0] == s[n-1]) {
            ans -= (k-1) * (cnt[0].second/2);
            ans -= (k-1) * (cnt[m-1].second/2);
            ans += (k-1) * ((cnt[0].second+cnt[m-1].second)/2);
        }
    }
    cout << ans << endl; 
}