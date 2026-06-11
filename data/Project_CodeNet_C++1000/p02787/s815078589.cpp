#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

ll dp[1100][11000];

int main() {
    ll h, n; cin >> h >> n;
    rep(i, 1100) rep(j, 11000) {
        if(j == 0) dp[i][j] = 0;
        else dp[i][j] = INF;
    }
    rep(i, n) {
        ll a, b; cin >> a >> b;
        rep(j, h+1) {
            chmin(dp[i+1][j], dp[i][j]);
            if(j <= a) chmin(dp[i+1][j], b);
            else chmin(dp[i+1][j], dp[i+1][j-a] + b);
        }
    }
    cout << dp[n][h] << endl;
}
