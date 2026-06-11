#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m, a;
    cin >> n >> m;
    vector<ll> b(n+100, 0);
    rep1(i, m){
        cin >> a;
        b[a]++;
    }
    vector<ll> dp(n+100, 0);
    dp[0] = 1;
    rep1(i, n){
        rep2(j, 1, 3){
            if (b[i+j]) continue;
            dp[i+j] += dp[i];
            dp[i+j] %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
    //printf("%.12f", ans);
}