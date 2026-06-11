#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll INF = 1ll<<60;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> dp(1ll<<n,INF); dp[0] = 0;
    rep(i,m){
        ll a, b; cin >> a >> b;
        ll count = 0;
        rep(i,b){
            ll c; cin >> c; c--;
            count |= 1<<c;
        }
        rrep(j,1ll<<n) chmin(dp[j|count],dp[j]+a);
    }
    if(dp[(1ll<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1ll<<n)-1] << endl;
    return 0;
}