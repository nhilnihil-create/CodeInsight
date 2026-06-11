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

ll dp[11000];

int main() {
    ll h, n; cin >> h >> n;
    rep(i, 11000) dp[i] = INF;
    dp[0] = 0;
    rep(i, n) {
        ll a, b; cin >> a >> b;
        rep(j, h) chmin(dp[min(h, j+a)], dp[j] + b);
    }
    cout << dp[h] << endl;
}
