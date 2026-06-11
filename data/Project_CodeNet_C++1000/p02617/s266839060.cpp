#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<int,int>> g(n-1);
    rep(i,n-1) {
        cin >> g[i].first >> g[i].second;
    }
    ll ans = 0;
    for(ll l = 1; l <= n; l++) {
        ans += (n-l+1)*(n-l+2)/2;
    }

    rep(i,n-1) {
        int l = min(g[i].first,g[i].second);
        int r = max(g[i].first,g[i].second);
        ans -= (n-r+1) * l;
    }
    cout << ans << endl;

}
