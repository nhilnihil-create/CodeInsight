#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    int n = s.size();
    map<char,vector<int>> m;
    rep(i,n) {
        m[s[i]].push_back(i);
    }
    ll ans = 0;
    int pre_idx = -1;
    rep(i, t.size()) {
        char c = t[i];
        if(m.count(c) == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto idx_itr = lower_bound(m[c].begin(), m[c].end(), pre_idx+1);
        if(idx_itr != m[c].end()) {
            pre_idx = *idx_itr;
        } else {
            pre_idx = -1;
            ans += n;
            auto idx_itr2 = lower_bound(m[c].begin(), m[c].end(), pre_idx+1);
            pre_idx = *idx_itr2;
        }
    }
    ans += pre_idx+1;
    cout << ans << endl;
}
