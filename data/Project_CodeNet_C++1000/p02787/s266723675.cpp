#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const ll INF = numeric_limits<ll>::max();
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main()
{
    int h, n; cin >> h >> n;
    VI a(n), b(n);rep(i, n) cin >> a[i] >> b[i];

    ll dp[10010]; rep(i, h+1) dp[i] = INF;
    dp[0] = 0;
    rep(i, h) {
        if (dp[i] == INF) continue;
        rep(j, n) {
            
            if (i + a[j] > h) {
                chmin(dp[h], dp[i] + b[j]);
            }else{
                chmin(dp[i + a[j]], dp[i] + b[j]);
            }
        }
    }
    cout << dp[h] << endl;
    return 0;
}