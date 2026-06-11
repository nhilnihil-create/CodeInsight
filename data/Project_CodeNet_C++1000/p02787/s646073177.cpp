#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, n;
    cin >> h >> n;
    vector<int> dp(h+10005, INF);
    dp[0] = 0;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        rep(j,h+1){
            chmin(dp[j+a], dp[j] + b);
        }
    }
    int ans = INF;
    for(int j = h; j <= h+10000; ++j) chmin(ans, dp[j]);
    cout << ans << endl;
    return 0;
}
