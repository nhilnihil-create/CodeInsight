#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int h,n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    int max_a = 0;
    rep(i,n) {
        cin >> a[i] >> b[i];
        chmax(max_a,a[i]);
    }
    int INF = INT32_MAX>>2;
    vector<int> dp(h+max_a,INF);
    dp[0] = 0;
    rep(i,h) rep(j,n) {
            chmin(dp[i+a[j]], dp[i]+b[j]);
    }
    int ans = INF>>2;
    rep(i,max_a) {
        chmin(ans, dp[h+i]);
    }
    cout << ans << endl;
}
